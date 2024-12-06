#pragma once

#include "notifications/notification.hpp"

template<typename Derived>
class Observer {
public:
    void notify(NotificationType type) {
        static_cast<Derived*>(this)->OnNotify(type);
    }
};

template<typename ObserverType, NotificationType Type>
struct ObserverRegistration {
    using Observer = ObserverType;
    static constexpr NotificationType NType = Type;
};
