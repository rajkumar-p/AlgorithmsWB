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

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    message(STATUS "Building binary with Debug flags")
    message(STATUS "Enabling static checker on the debug binary")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer")
elseif(CMAKE_BUILD_TYPE MATCHES "Profile")
    message(STATUS "Building binary with Debug flags")
    message(STATUS "Building binary for gprof profiling")
    message(STATUS "Not enabling static checker on the debug binary")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pg")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "Building binary with Release flags")
    message(STATUS "Not enabling static checker on the release binary")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra")
endif()

add_library(Catch INTERFACE)

# Setup include directories
include_directories(include)
include_directories(test/include)

add_executable(aw src/main.cpp include/string_algorithms.hpp src/string_algorithms.cpp src/array_algorithms.cpp
        include/array_algorithms.hpp include/bstree_node.hpp src/sorting_algorithms.cpp
        include/sorting_algorithms.hpp src/dp_algorithms.cpp include/dp_algorithms.hpp include/bstree.hpp
        src/bstree_algorithms.cpp include/bstree_algorithms.hpp
        src/searching_algorithms.cpp include/searching_algorithms.hpp src/counting_algorithms.cpp
        include/counting_algorithms.hpp include/binary_search_tree_node.h)

add_executable(aw_tests test/src/aw_tests.cpp src/string_algorithms.cpp test/src/string_algorithms_tests.cpp
        src/array_algorithms.cpp include/array_algorithms.hpp test/src/array_algorithms_tests.cpp
        src/sorting_algorithms.cpp include/sorting_algorithms.hpp test/src/sorting_algorithms_tests.cpp
        src/dp_algorithms.cpp include/dp_algorithms.hpp test/src/dp_algorithms_tests.cpp include/bstree.hpp
        test/src/bstree_tests.cpp src/bstree_algorithms.cpp include/bstree_algorithms.hpp
        test/src/bstree_algorithms_tests.cpp src/searching_algorithms.cpp include/searching_algorithms.hpp
        test/src/searching_algorithms_tests.cpp src/counting_algorithms.cpp include/counting_algorithms.hpp
        test/src/counting_algorithms_tests.cpp include/binary_search_tree_node.h)

add_executable(aw_profile src/profile.cpp include/string_algorithms.hpp src/string_algorithms.cpp src/array_algorithms.cpp
        include/array_algorithms.hpp include/bstree_node.hpp src/sorting_algorithms.cpp
        include/sorting_algorithms.hpp src/dp_algorithms.cpp include/dp_algorithms.hpp include/bstree.hpp
        src/bstree_algorithms.cpp include/bstree_algorithms.hpp
        src/searching_algorithms.cpp include/searching_algorithms.hpp src/counting_algorithms.cpp
        include/counting_algorithms.hpp include/binary_search_tree_node.h)

# Package executables to specific directory
set_target_properties(aw PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/debug)
set_target_properties(aw PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/release)
set_target_properties(aw_tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/test)
set_target_properties(aw_profile PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/profile)
