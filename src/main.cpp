#include "config/system_config.hpp"
#include "notifications/notification.hpp"

int main() {
  uint32_t iteration = 0;
  System::GetTaskManager().Bootstrap();
  System::GetTaskManager().Setup();
  SystemInterruptManager::registerNotification(
      NotificationType::MESSAGE_ARRIVED);
  while (iteration < 10) {
    System::GetTaskManager().Loop();
    iteration++;
  }
  return 0;
}
