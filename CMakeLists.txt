cmake_minimum_required(VERSION 3.20)

include(${BRISK_DIR}/cmake/brisk.cmake)

project(brisk-example)

brisk_setup()

add_executable(main main.cpp)

target_link_libraries(main PRIVATE brisk-widgets brisk-executable)

brisk_metadata(
    VENDOR "Brisk"
    NAME "Example"
    DESCRIPTION "Brisk example"
    VERSION "0.1.2.3"
    COPYRIGHT "© 2024 Brisk"
    ICON ${CMAKE_SOURCE_DIR}/icon.png
    APPLE_BUNDLE com.brisklib.main
)

brisk_setup_executable(main)
