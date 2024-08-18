#ifdef SPU_JULIA

#include <sstream>

#include "Module/Stateless/Stateless_Julia.hpp"
#include "Tools/Exception/exception.hpp"

using namespace spu;
using namespace spu::module;

int32_t
Stateless_Julia::jl_call_func(const std::vector<void*>& args, const bool jl_safe)
{
    jluna::unsafe::Value* jl_ret;
    size_t n_args = args.size();
    if (n_args == 1)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]));
    }
    else if (n_args == 2)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]));
    }
    else if (n_args == 3)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]));
    }
    else if (n_args == 4)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]));
    }
    else if (n_args == 5)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]),
                                      static_cast<jluna::unsafe::Value*>(args[4]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]),
                                         static_cast<jluna::unsafe::Value*>(args[4]));
    }
    else if (n_args == 6)
    {
        if (jl_safe)
        {
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]),
                                      static_cast<jluna::unsafe::Value*>(args[4]),
                                      static_cast<jluna::unsafe::Value*>(args[5]));
        }
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]),
                                         static_cast<jluna::unsafe::Value*>(args[4]),
                                         static_cast<jluna::unsafe::Value*>(args[5]));
    }
    else if (n_args == 7)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]),
                                      static_cast<jluna::unsafe::Value*>(args[4]),
                                      static_cast<jluna::unsafe::Value*>(args[5]),
                                      static_cast<jluna::unsafe::Value*>(args[6]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]),
                                         static_cast<jluna::unsafe::Value*>(args[4]),
                                         static_cast<jluna::unsafe::Value*>(args[5]),
                                         static_cast<jluna::unsafe::Value*>(args[6]));
    }
    else if (n_args == 8)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]),
                                      static_cast<jluna::unsafe::Value*>(args[4]),
                                      static_cast<jluna::unsafe::Value*>(args[5]),
                                      static_cast<jluna::unsafe::Value*>(args[6]),
                                      static_cast<jluna::unsafe::Value*>(args[7]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]),
                                         static_cast<jluna::unsafe::Value*>(args[4]),
                                         static_cast<jluna::unsafe::Value*>(args[5]),
                                         static_cast<jluna::unsafe::Value*>(args[6]),
                                         static_cast<jluna::unsafe::Value*>(args[7]));
    }
    else if (n_args == 9)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]),
                                      static_cast<jluna::unsafe::Value*>(args[4]),
                                      static_cast<jluna::unsafe::Value*>(args[5]),
                                      static_cast<jluna::unsafe::Value*>(args[6]),
                                      static_cast<jluna::unsafe::Value*>(args[7]),
                                      static_cast<jluna::unsafe::Value*>(args[8]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]),
                                         static_cast<jluna::unsafe::Value*>(args[4]),
                                         static_cast<jluna::unsafe::Value*>(args[5]),
                                         static_cast<jluna::unsafe::Value*>(args[6]),
                                         static_cast<jluna::unsafe::Value*>(args[7]),
                                         static_cast<jluna::unsafe::Value*>(args[8]));
    }
    else if (n_args == 10)
    {
        if (jl_safe)
            jl_ret = jluna::safe_call(static_cast<jluna::unsafe::Function*>(args[0]),
                                      static_cast<jluna::unsafe::Value*>(args[1]),
                                      static_cast<jluna::unsafe::Value*>(args[2]),
                                      static_cast<jluna::unsafe::Value*>(args[3]),
                                      static_cast<jluna::unsafe::Value*>(args[4]),
                                      static_cast<jluna::unsafe::Value*>(args[5]),
                                      static_cast<jluna::unsafe::Value*>(args[6]),
                                      static_cast<jluna::unsafe::Value*>(args[7]),
                                      static_cast<jluna::unsafe::Value*>(args[8]),
                                      static_cast<jluna::unsafe::Value*>(args[9]));
        else
            jl_ret = jluna::unsafe::call(static_cast<jluna::unsafe::Function*>(args[0]),
                                         static_cast<jluna::unsafe::Value*>(args[1]),
                                         static_cast<jluna::unsafe::Value*>(args[2]),
                                         static_cast<jluna::unsafe::Value*>(args[3]),
                                         static_cast<jluna::unsafe::Value*>(args[4]),
                                         static_cast<jluna::unsafe::Value*>(args[5]),
                                         static_cast<jluna::unsafe::Value*>(args[6]),
                                         static_cast<jluna::unsafe::Value*>(args[7]),
                                         static_cast<jluna::unsafe::Value*>(args[8]),
                                         static_cast<jluna::unsafe::Value*>(args[9]));
    }
    else
    {
        std::stringstream message;
        message << "Only n_args <= 10 is supported ('n_args' = " << n_args << ").";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }

    if (jl_safe)
        return jluna::unbox<int32_t>(jl_ret);
    else
        return jluna::unsafe::unsafe_unbox<int32_t>(jl_ret);
}

jluna::unsafe::Array*
Stateless_Julia::jl_new_array_from_data(const runtime::Socket* sck)
{
    void* p = sck->get_dataptr();
    size_t e = sck->get_n_elmts();
    if (sck->get_datatype() == typeid(uint8_t))
        return jluna::unsafe::new_array_from_data(jluna::UInt8_t, p, e);
    else if (sck->get_datatype() == typeid(int8_t))
        return jluna::unsafe::new_array_from_data(jluna::Int8_t, p, e);
    else if (sck->get_datatype() == typeid(uint16_t))
        return jluna::unsafe::new_array_from_data(jluna::UInt16_t, p, e);
    else if (sck->get_datatype() == typeid(int16_t))
        return jluna::unsafe::new_array_from_data(jluna::Int16_t, p, e);
    else if (sck->get_datatype() == typeid(uint32_t))
        return jluna::unsafe::new_array_from_data(jluna::UInt32_t, p, e);
    else if (sck->get_datatype() == typeid(int32_t))
        return jluna::unsafe::new_array_from_data(jluna::Int32_t, p, e);
    else if (sck->get_datatype() == typeid(uint64_t))
        return jluna::unsafe::new_array_from_data(jluna::UInt64_t, p, e);
    else if (sck->get_datatype() == typeid(int64_t))
        return jluna::unsafe::new_array_from_data(jluna::Int64_t, p, e);
    else if (sck->get_datatype() == typeid(float))
        return jluna::unsafe::new_array_from_data(jluna::Float32_t, p, e);
    else if (sck->get_datatype() == typeid(double))
        return jluna::unsafe::new_array_from_data(jluna::Float64_t, p, e);
    else
    {
        std::stringstream message;
        message << "Unsupported socket datatype ('sck->get_datatype_string()' = " << sck->get_datatype_string() << ").";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }
}

size_t
Stateless_Julia::get_task_id(runtime::Task& task)
{
    auto& module = task.get_module();
    for (size_t tid = 0; tid < module.tasks.size(); tid++)
        if (&task == module.tasks[tid].get()) return tid;

    std::stringstream message;
    message << "Task is not in the current module, this should never happen.";
    throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
}

Stateless_Julia::Stateless_Julia(bool jl_safe)
  : Module()
  , evaluated(false)
  , jl_safe(jl_safe)
  , cloned(false)
  , jl_create_constants(new std::vector<std::vector<std::function<void(Stateless_Julia& m)>>>())
  , jl_evaluate(new std::vector<std::function<void()>>())
  , jl_create_codelet(new std::vector<std::function<void(Stateless_Julia& m)>>())
{
}

Stateless_Julia::~Stateless_Julia()
{
    for (size_t tid = 0; tid < this->jl_constants_id.size(); tid++)
        for (size_t jl_id : this->jl_constants_id[tid])
            jluna::unsafe::gc_release(jl_id);
}

Stateless_Julia*
Stateless_Julia::clone() const
{
    auto m = new Stateless_Julia(*this);
    m->deep_copy(*this);
    return m;
}

void
Stateless_Julia::deep_copy(const Stateless_Julia& m)
{
    Module::deep_copy(m);
    this->cloned = true;
    this->reset();
}

void
Stateless_Julia::reset()
{
    for (auto& ptrs_list : this->jl_constants_ptr)
        ptrs_list.clear();
    for (auto& ids_list : this->jl_constants_id)
        ids_list.clear();
    for (auto& funcs_list : this->jl_func_args)
        funcs_list.clear();

    this->evaluated = false;
}

bool
Stateless_Julia::is_eval() const
{
    return this->evaluated;
}

void
Stateless_Julia::set_jl_safety(const bool jl_safe)
{
    this->jl_safe = jl_safe;
}

bool
Stateless_Julia::is_jl_safe()
{
    return this->jl_safe;
}

void
Stateless_Julia::eval()
{
    if (this->is_eval())
    {
        std::stringstream message;
        message << "This module has already been evaluated.";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }

    if ((*this->jl_evaluate).size() == 0)
    {
        std::stringstream message;
        message << "There is no Julia code to evaluate, please call the 'Stateless_Julia::create_codelet()' "
                   "method first.";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }

    for (size_t tid = 0; tid < this->tasks.size(); tid++)
    {
        for (auto& create_constant : (*this->jl_create_constants)[tid])
            create_constant(*this);
        (*this->jl_evaluate)[tid]();
        (*this->jl_create_codelet)[tid](*this);
    }

    this->evaluated = true;
}

runtime::Task&
Stateless_Julia::create_task(const std::string& name)
{
    if (this->cloned)
    {
        std::stringstream message;
        message << "It is not possible to create a new task on a clone.";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }

    this->jl_create_constants->push_back(std::vector<std::function<void(Stateless_Julia & m)>>());
    this->jl_constants_ptr.push_back(std::vector<jluna::unsafe::Value*>());
    this->jl_constants_id.push_back(std::vector<size_t>());
    this->jl_func_args.push_back(std::vector<void*>());

    return Module::create_task(name);
}

runtime::Task&
Stateless_Julia::create_tsk(const std::string& name)
{
    return this->create_task(name);
}

void
Stateless_Julia::create_codelet(runtime::Task& task, const std::string& julia_code)
{
    if (this->cloned)
    {
        std::stringstream message;
        message << "It is not possible to create a new codelet on a clone.";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }

    this->jl_evaluate->push_back([julia_code]() { jluna::Main.safe_eval(julia_code); });
    size_t tid = Stateless_Julia::get_task_id(task);
    (*this->jl_evaluate)[tid]();
    this->_create_codelet(task);
}

void
Stateless_Julia::create_cdl(runtime::Task& task, const std::string& julia_code)
{
    this->create_codelet(task, julia_code);
}

void
Stateless_Julia::create_codelet_file(runtime::Task& task, const std::string& julia_filepath)
{
    if (this->cloned)
    {
        std::stringstream message;
        message << "It is not possible to create a new codelet on a clone.";
        throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
    }

    this->jl_evaluate->push_back([julia_filepath]() { jluna::Main.safe_eval_file(julia_filepath); });
    size_t tid = Stateless_Julia::get_task_id(task);
    (*this->jl_evaluate)[tid]();
    this->_create_codelet(task);
}

void
Stateless_Julia::create_cdl_file(runtime::Task& task, const std::string& julia_filepath)
{
    this->create_codelet_file(task, julia_filepath);
}

void
Stateless_Julia::_create_codelet(runtime::Task& task)
{
    size_t tid = Stateless_Julia::get_task_id(task);

    Module::create_codelet(task,
                           [tid](module::Module& m, runtime::Task& t, const size_t frame_id)
                           {
                               auto& sjl = static_cast<Stateless_Julia&>(m);

                               if (!sjl.is_eval())
                               {
                                   std::stringstream message;
                                   message << "The task cannot be executed because the module has not been evaluated.";
                                   throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
                               }

                               for (size_t s = 0; s < t.sockets.size() - 1; s++)
                               {
                                   const runtime::Socket* sck = t.sockets[s].get();
                                   sjl.jl_func_args[tid][s + 1] = (void*)Stateless_Julia::jl_new_array_from_data(sck);
                               }

                               *(int32_t*)sjl.jl_func_args[tid][sjl.jl_func_args[tid].size() - 2] = frame_id;
                               *(int32_t*)sjl.jl_func_args[tid][sjl.jl_func_args[tid].size() - 1] =
                                 sjl.get_n_frames_per_wave();

                               return Stateless_Julia::jl_call_func(sjl.jl_func_args[tid], sjl.is_jl_safe());
                           });

    this->jl_create_codelet->push_back(
      [tid](Stateless_Julia& m)
      {
          runtime::Task& task = *(m.tasks[tid].get());
          if (m.jl_func_args[tid].size() > 0)
          {
              std::stringstream message;
              message << "jl_func_args[tid] has to be empty ('jl_func_args[tid].size()' = "
                      << m.jl_func_args[tid].size() << ", 'tid' = " << tid << ").";
              throw tools::runtime_error(__FILE__, __LINE__, __func__, message.str());
          }

          m.jl_func_args[tid].resize(1 + task.sockets.size() + m.jl_constants_ptr[tid].size() + 1);

          jluna::unsafe::Function* jl_codelet =
            jluna::unsafe::get_function(jluna::Main, jluna::Symbol(task.get_name()));

          m.jl_func_args[tid][0] = (void*)jl_codelet;

          for (size_t i = 0; i < m.jl_constants_ptr[tid].size(); i++)
              m.jl_func_args[tid][m.jl_func_args[tid].size() - (m.jl_constants_ptr[tid].size() + 2) + i] =
                (void*)m.jl_constants_ptr[tid][i];

          jluna::unsafe::Value* jl_frame_id = jluna::box<uint32_t>(0);
          size_t jl_frame_id_id = jluna::unsafe::gc_preserve(jl_frame_id);
          m.jl_constants_ptr[tid].push_back(jl_frame_id);
          m.jl_constants_id[tid].push_back(jl_frame_id_id);
          m.jl_func_args[tid][m.jl_func_args[tid].size() - 2] = (void*)jl_frame_id;

          jluna::unsafe::Value* jl_n_frames_per_wave = jluna::box<uint32_t>(m.get_n_frames_per_wave());
          size_t jl_n_frames_per_wave_id = jluna::unsafe::gc_preserve(jl_frame_id);
          m.jl_constants_ptr[tid].push_back(jl_n_frames_per_wave);
          m.jl_constants_id[tid].push_back(jl_n_frames_per_wave_id);
          m.jl_func_args[tid][m.jl_func_args[tid].size() - 1] = (void*)jl_n_frames_per_wave;
      });

    (*this->jl_create_codelet)[tid](*this);
}

#endif /* SPU_JULIA */
