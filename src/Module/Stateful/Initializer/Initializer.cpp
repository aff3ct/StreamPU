#include <algorithm>
#include <chrono>
#include <sstream>
#include <string>
#include <thread>

#include "Module/Stateful/Initializer/Initializer.hpp"

using namespace spu;
using namespace spu::module;

template<typename T>
Initializer<T>::Initializer(const size_t n_elmts, const size_t ns)
  : Stateful()
  , init_data(this->get_n_frames(), std::vector<T>(n_elmts, 0))
  , ns(ns)
{
    const std::string name = "Initializer";
    this->set_name(name);
    this->set_short_name(name);

    if (n_elmts == 0)
    {
        std::stringstream message;
        message << "'n_elmts' has to be greater than 0.";
        throw tools::invalid_argument(__FILE__, __LINE__, __func__, message.str());
    }

    auto& p = this->create_task("initialize");
    auto ps_out = this->template create_socket_out<T>(p, "out", n_elmts);
    this->create_codelet(p,
                         [ps_out](Module& m, runtime::Task& t, const size_t frame_id) -> int
                         {
                             auto& ini = static_cast<Initializer&>(m);
                             ini._initialize(t[ps_out].template get_dataptr<T>(), frame_id);
                             return runtime::status_t::SUCCESS;
                         });
}

template<typename T>
Initializer<T>*
Initializer<T>::clone() const
{
    auto m = new Initializer(*this);
    m->deep_copy(*this);
    return m;
}

template<typename T>
size_t
Initializer<T>::get_ns() const
{
    return this->ns;
}

template<typename T>
void
Initializer<T>::set_ns(const size_t ns)
{
    this->ns = ns;
}

template<typename T>
const std::vector<std::vector<T>>&
Initializer<T>::get_init_data() const
{
    return this->init_data;
}

template<typename T>
void
Initializer<T>::set_init_data(const std::vector<T>& init_data)
{
    if (init_data.size() != this->init_data[0].size())
    {
        std::stringstream message;
        message << "'init_data.size()' has to be equal to 'this->init_data[0].size()' ('init_data.size()' = "
                << init_data.size() << ", 'this->init_data[0].size()' = " << this->init_data[0].size() << ").";
        throw tools::invalid_argument(__FILE__, __LINE__, __func__, message.str());
    }

    for (auto& ini : this->init_data)
        ini = init_data;
}

template<typename T>
void
Initializer<T>::set_init_data(const std::vector<std::vector<T>>& init_data)
{
    if (init_data.size() != this->get_n_frames())
    {
        std::stringstream message;
        message << "'init_data.size()' has to be equal to 'this->get_n_frames()' ('init_data.size()' = "
                << init_data.size() << ", 'this->get_n_frames()' = " << this->get_n_frames() << ").";
        throw tools::invalid_argument(__FILE__, __LINE__, __func__, message.str());
    }

    for (size_t f = 0; f < init_data.size(); f++)
    {
        if (init_data[f].size() != this->init_data[f].size())
        {
            std::stringstream message;
            message << "'init_data[f].size()' has to be equal to 'this->init_data[f].size()' ('init_data[f].size()' = "
                    << init_data[f].size() << ", 'this->init_data[f].size()' = " << this->init_data[f].size()
                    << ", 'f' = " << f << ").";
            throw tools::invalid_argument(__FILE__, __LINE__, __func__, message.str());
        }
        this->init_data[f] = init_data[f];
    }
}

template<typename T>
void
Initializer<T>::set_init_data(const T val)
{
    for (auto& ini : this->init_data)
        std::fill(ini.begin(), ini.end(), val);
}

template<typename T>
void
Initializer<T>::set_n_frames(const size_t n_frames)
{
    const auto old_n_frames = this->get_n_frames();
    if (old_n_frames != n_frames)
    {
        Module::set_n_frames(n_frames);

        this->init_data.resize(n_frames);
        for (size_t f = old_n_frames; f < n_frames; f++)
            this->init_data[f] = this->init_data[0];
    }
}

template<typename T>
void
Initializer<T>::initialize(T* out, const int frame_id, const bool managed_memory)
{
    (*this)[ini::sck::initialize::out].bind(out);
    (*this)[ini::tsk::initialize].exec(frame_id, managed_memory);
}

template<typename T>
void
Initializer<T>::_initialize(T* out, const size_t frame_id)
{
    std::chrono::time_point<std::chrono::steady_clock> t_start;
    if (this->ns) t_start = std::chrono::steady_clock::now();

    std::copy(this->init_data[frame_id].begin(), this->init_data[frame_id].end(), out);

    if (this->ns)
    {
        std::chrono::nanoseconds duration = std::chrono::steady_clock::now() - t_start;
        while ((size_t)duration.count() < this->ns) // active waiting
            duration = std::chrono::steady_clock::now() - t_start;
    }
}

// ==================================================================================== explicit template instantiation
template class spu::module::Initializer<int8_t>;
template class spu::module::Initializer<uint8_t>;
template class spu::module::Initializer<int16_t>;
template class spu::module::Initializer<uint16_t>;
template class spu::module::Initializer<int32_t>;
template class spu::module::Initializer<uint32_t>;
template class spu::module::Initializer<int64_t>;
template class spu::module::Initializer<uint64_t>;
template class spu::module::Initializer<float>;
template class spu::module::Initializer<double>;
// ==================================================================================== explicit template instantiation
