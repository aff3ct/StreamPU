/*!
 * \file
 * \brief Class sched::Scheduler.
 */
#ifndef SCHEDULER_HPP__
#define SCHEDULER_HPP__

#include "Runtime/Pipeline/Pipeline.hpp"
#include "Runtime/Sequence/Sequence.hpp"
#include "Tools/Interface/Interface_reset.hpp"
#include <chrono>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

namespace spu
{
namespace sched
{
struct task_desc_t
{
    runtime::Task* tptr;
    std::chrono::duration<double, std::nano> exec_duration;
};
class Scheduler : public tools::Interface_reset
{
  public:
    Scheduler(runtime::Sequence& sequence);
    Scheduler(runtime::Sequence* sequence);
    Scheduler(std::unique_ptr<spu::runtime::Sequence> sequence);
    void profile();
    void print_profiling();

  protected:
    runtime::Sequence* sequence;
    std::vector<task_desc_t> tasks_desc;

  public:
    virtual ~Scheduler() = default;
    virtual runtime::Pipeline* generate_pipeline() = 0;
    virtual void reset();
};
} // namespace sched
} // namespace spu

#endif // SCHEDULER_HPP__