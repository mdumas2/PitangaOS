#pragma once
#include "task/task.hpp"

namespace Driver {
class Led : public App::Task<Led> {
 private:
  void Bootstrap() {}
  void Setup() {}
  void Loop() { m_private++; }
  friend class App::Task<Led>;
  volatile int m_private = 0;
};
}  // namespace Driver
