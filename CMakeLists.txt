cmake_minimum_required(VERSION 3.5)

project(PitangaOS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(PitangaOS 
    src/main.cpp
    include/notifications/notification.hpp
    include/notifications/observer.hpp
    include/config/system_config.hpp
    include/type_lists/type_list.hpp
    include/manager/interrupt_manager.hpp
    include/manager/collect_registrations.hpp
    include/drivers/serial.hpp
)

include(GNUInstallDirs)
install(TARGETS PitangaOS
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
