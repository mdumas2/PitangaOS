#include "notifications/notification.hpp"
#include "config/system_config.hpp"

int main() {
    // Use the predefined SystemInterruptManager
    SystemInterruptManager::registerNotification(NotificationType::MESSAGE_ARRIVED);
    SystemInterruptManager::notifyAll();

    return 0;
}
