#pragma once

#include "notifications/observer.hpp"
#include "notifications/notification.hpp"
#include "type_lists/type_list.hpp"
#include <iostream>

class Serial : public Observer<Serial> {
public:
    constexpr Serial() = default;

    static constexpr auto registrations() {
        return TypeList<ObserverRegistration<Serial, NotificationType::MESSAGE_ARRIVED>>{};
    }

private:
    friend class Observer;
    void OnNotify(NotificationType type) {
        if (type == NotificationType::MESSAGE_ARRIVED) {
            // Handle the message arrival
            std::cout << "Chegou\n";
        }
    }
};
