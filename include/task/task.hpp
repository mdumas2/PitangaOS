#pragma once

namespace App {
template<typename Derived>
class Task {
private:
    void BootstrapBase() {
        static_cast<Derived*>(this)->Bootstrap();
    }

    void SetupBase() {
        static_cast<Derived*>(this)->Setup();
    }

    void LoopBase() {
        static_cast<Derived*>(this)->Loop();
    }
    template<typename... Tasks>
    friend class TaskManager;
};
}
