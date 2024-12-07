#pragma once

#include <array>

#include "manager/collect_registrations.hpp"
#include "notifications/notification.hpp"
#include "notifications/observer.hpp"

template <typename RegistrationList, std::size_t MaxNotifications = 10>
class InterruptManager {
 private:
  static inline std::array<NotificationType, MaxNotifications>
      pendingNotifications{};
  static inline std::size_t notificationCount = 0;

 public:
  static void registerNotification(NotificationType type) {
    if (notificationCount < MaxNotifications) {
      pendingNotifications[notificationCount++] = type;
    }
  }

  static void notifyAll() { notifyStaticObservers(RegistrationList{}); }

 private:
  template <typename... Registrations>
  static void notifyStaticObservers(TypeList<Registrations...>) {
    (notifyStaticObserver<Registrations>(), ...);
  }

  template <typename Registration>
  static void notifyStaticObserver() {
    for (std::size_t i = 0; i < notificationCount; ++i) {
      if (pendingNotifications[i] == Registration::NType) {
        DerivedObserver<typename Registration::Observer>::instance().notify(
            Registration::NType);
      }
    }
    notificationCount = 0;
  }

  template <typename Observer>
  struct DerivedObserver {
    static constexpr Observer& instance() {
      static Observer observerInstance;
      return observerInstance;
    }
  };
};
