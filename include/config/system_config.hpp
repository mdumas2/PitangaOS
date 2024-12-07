#pragma once

#include "drivers/led.hpp"
#include "drivers/serial.hpp"
#include "manager/task_manager.hpp"

namespace System {
Driver::Led led;
Driver::Serial serial;

App::TaskManager<Driver::Led, Driver::Serial>& GetTaskManager() {
  static App::TaskManager<Driver::Led, Driver::Serial> taskManager{led, serial};
  return taskManager;
}
}  // namespace System
