#pragma once

#include "drivers/serial.hpp"
#include "manager/collect_registrations.hpp"
#include "manager/interrupt_manager.hpp"

using RegistrationList = typename CollectRegistrations<Driver::Serial>::type;
using SystemInterruptManager = InterruptManager<RegistrationList>;
