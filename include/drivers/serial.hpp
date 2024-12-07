#pragma once

#include "notifications/observer.hpp"
#include "notifications/notification.hpp"
#include "type_lists/type_list.hpp"
#include "task/task.hpp"
#include <iostream>

namespace Driver {
class Serial : public App::Task<Serial>, public Observer<Serial> {
public:
    constexpr Serial() = default;

    static constexpr auto registrations() {
        return TypeList<ObserverRegistration<Serial, NotificationType::MESSAGE_ARRIVED>>{};
    }

private:
    void Bootstrap() {}
    void Setup() {}
    void Loop() { m_private++; }

    void OnNotify(NotificationType type) {
        if (type == NotificationType::MESSAGE_ARRIVED) {
            // Handle the message arrival
            std::cout << "Chegou\n";
        }
    }

    friend class Observer;
    friend class App::Task<Serial>;
    volatile int m_private = 0;

};
}
