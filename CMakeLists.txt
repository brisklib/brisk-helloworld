cmake_minimum_required(VERSION 3.16)

# Initialize Brisk CMake modules. This must be before the first project directive
include(${BRISK_DIR}/cmake/brisk.cmake)

project(brisk-example)

# Set up the Brisk environment. This line must be after the project directive.
brisk_setup()

# Add an executable target named 'main' that will be built from the main.cpp source file
add_executable(main main.cpp)

# Link the required Brisk libraries (widgets and executable) to the 'main' target
target_link_libraries(main PRIVATE brisk-widgets brisk-executable)

# Provide metadata for the application
brisk_metadata(
    VENDOR "Brisk"                 # Name of the vendor or company
    NAME "Example"                 # Application name
    DESCRIPTION "Brisk example"    # Short description of the application
    VERSION "0.1.2.3"              # Version number of the application
    COPYRIGHT "© 2024 Brisk"       # Copyright information
    ICON ${CMAKE_SOURCE_DIR}/icon.png  # Path to the application icon (PNG)
    APPLE_BUNDLE com.brisklib.main  # Bundle identifier for Apple platforms
)

# Perform additional setup tasks specific to the executable target 'main'
brisk_setup_executable(main)
