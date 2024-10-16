# Brisk Example Project

This project demonstrates how to use the [Brisk C++ library](https://github.com/brisklib/brisk) to build an application using CMake. It includes a simple executable that links to the Brisk library.

## Prerequisites

To build and run this project, ensure you have the following installed:

- **C++ compiler** supporting C++20 or later
- **CMake** version 3.16 or higher
- **Brisk Library** source code (Ensure `BRISK_DIR` is properly set to the location of the Brisk repository: `-DBRISK_DIR=path/to/brisk/repository`)

## Project Structure

- `main.cpp`: This file contains the entry point and core logic for the example application.
- `CMakeLists.txt`: Configuration file for CMake to build the project and link necessary libraries.

## Building the Project

1. Clone or download the repository to your local machine.
2. Navigate to the project directory:
    ```bash
    cd path/to/project
    ```
3. Create a build directory and navigate into it:
    ```bash
    mkdir build && cd build
    ```
4. Run CMake to configure the project:
    ```bash
    cmake -DBRISK_DIR=path/to/brisk/repository -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
    ```
5. Build the project:
    ```bash
    cmake --build .
    ```

## Dependencies

The Brisk dependencies are built using the [vcpkg package manager](https://github.com/microsoft/vcpkg/). Vcpkg manages the dependencies by using source packages and builds each dependent library from its sources, which may lead to significant build times on the first run. It is recommended to set up a [binary cache](https://learn.microsoft.com/en-us/vcpkg/users/binarycaching) to reuse built libraries across multiple Brisk projects.

## CMake Configuration

The provided `CMakeLists.txt` file includes the following key components:

- **Project Setup**: The project is configured with the `brisk_setup()` function, and the metadata for the application is defined via `brisk_metadata()`.
- **Executable Setup**: The project compiles the `main.cpp` file into an executable and links it to the Brisk libraries (`brisk-widgets` and `brisk-executable`).

```cmake
add_executable(main main.cpp)

target_link_libraries(main PRIVATE brisk-widgets brisk-executable)
```

Ensure that the Brisk library is available and properly linked in your environment.

## License

The Brisk library is licensed under a dual GPLv2+/Commercial license.

The example project contained in this repository is licensed under the public domain or CC0. You are free to modify this code and use it as a starting point for your own projects, either GPL-licensed or proprietary (provided you have acquired a commercial license for the Brisk library, for details, contact brisk@brisklib.com).

