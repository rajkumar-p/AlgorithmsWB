cmake_minimum_required(VERSION 3.12)

# Setup project name
project(AlgorithmsWorkbench)

# Use C++14
set(CMAKE_CXX_STANDARD 14)

# Make debug config the default build type
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type passed, default to Debug")
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type (default Debug)" FORCE)
endif()

# Compiler options for specific configurations
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")

add_library(Catch INTERFACE)

# Setup include directories
include_directories(include)
include_directories(test/include)

add_executable(aw src/main.cpp include/string_algorithms.hpp src/string_algorithms.cpp src/array_algorithms.cpp
        include/array_algorithms.hpp include/bstree_node.hpp src/sorting_algorithms.cpp
        include/sorting_algorithms.hpp src/dp_algorithms.cpp include/dp_algorithms.hpp)
add_executable(aw_tests test/src/aw_tests.cpp src/string_algorithms.cpp test/src/string_algorithms_tests.cpp
        src/array_algorithms.cpp include/array_algorithms.hpp test/src/array_algorithms_tests.cpp
        src/sorting_algorithms.cpp include/sorting_algorithms.hpp test/src/sorting_algorithms_tests.cpp
        src/dp_algorithms.cpp include/dp_algorithms.hpp test/src/dp_algorithms_tests.cpp)

# Package executables to specific directory
set_target_properties(aw PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set_target_properties(aw PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)
set_target_properties(aw_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/test)
