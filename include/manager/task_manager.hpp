#pragma once
#include <tuple>

#include "config/system_config_interrupt.hpp"
#include "task/task.hpp"

namespace App {
template <typename... Tasks>
class TaskManager final {
 public:
  constexpr TaskManager(Tasks&... tasks) : m_tasks{tasks...} {}

  void Bootstrap() {
    std::apply([](auto&... tasks) { (tasks.BootstrapBase(), ...); }, m_tasks);
  }

  void Setup() {
    std::apply([](auto&... tasks) { (tasks.SetupBase(), ...); }, m_tasks);
  }

  void Loop() { Loop(std::make_index_sequence<sizeof...(Tasks)>{}); }

 private:
  std::tuple<Tasks&...> m_tasks;

  template <std::size_t... I>
  void Loop(std::index_sequence<I...>) {
    auto callTask = [this](auto i) { this->call_loop(std::get<i>(m_tasks)); };
    SystemInterruptManager::notifyAll();
    (..., callTask(std::integral_constant<std::size_t, I>{}));
  }

  template <typename T>
  void call_loop(T& task) {
    (static_cast<App::Task<std::remove_reference_t<T>>*>(&task)->LoopBase());
  }
};
}  // namespace App
