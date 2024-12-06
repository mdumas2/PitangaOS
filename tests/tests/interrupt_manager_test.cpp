#include <gtest/gtest.h>
#include "manager/interrupt_manager.hpp"
#include "drivers/serial.hpp"

TEST(InterruptManagerTest, RegisterNotification) {
    InterruptManager<RegistrationList>::registerNotification(NotificationType::MESSAGE_ARRIVED);
    EXPECT_EQ(true, true); // Placeholder for your actual test logic
}

TEST(InterruptManagerTest, NotifyAll) {
    InterruptManager<RegistrationList>::notifyAll();
    EXPECT_EQ(true, true); // Placeholder for your actual test logic
}
