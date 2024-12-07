#pragma once

#include "notifications/notification.hpp"
#include "notifications/observer.hpp"

template <typename Observer>
struct GetObserverRegistrations {
  using type = decltype(Observer::registrations());
};

template <typename... Observers>
struct CollectRegistrations;

template <typename Observer, typename... Rest>
struct CollectRegistrations<Observer, Rest...> {
  using type = typename ConcatTypeLists<
      typename GetObserverRegistrations<Observer>::type,
      typename CollectRegistrations<Rest...>::type>::type;
};

template <>
struct CollectRegistrations<> {
  using type = TypeList<>;
};
