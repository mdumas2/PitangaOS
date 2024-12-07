#pragma once

#include "drivers/serial.hpp"
#include "drivers/led.hpp"
#include "manager/task_manager.hpp"

namespace System {
Driver::Led led;
Driver::Serial serial;

App::TaskManager<Driver::Led, Driver::Serial>& GetTaskManager() {
    static App::TaskManager<Driver::Led, Driver::Serial> taskManager{led, serial};
    return taskManager;
}
}
