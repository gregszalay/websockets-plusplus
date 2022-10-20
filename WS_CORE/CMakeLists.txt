cmake_minimum_required(VERSION 3.5)

project(ws_core_library)

# find_package(Threads REQUIRED)
find_package(Boost 1.80.0 REQUIRED)

# Include our own module path. This makes #include "x.h"
# work in project subfolders to include the main directory headers.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Generate the static library from the library sources
add_library(ws_core_library STATIC
    "include/HELLO/Hello.cpp"
    "include/SERVERSTUFF/ServerStuff.cpp"
    "include/BASE/Base.cpp"
)
target_include_directories(ws_core_library
    PUBLIC
    ${PROJECT_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS}
    PRIVATE
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# ###########################################################
# Create an executable
# ###########################################################

# Add an executable with the above sources
add_executable(ws_core_binary
    main.cpp
)

# link the new ws_core_library target with the ws_core_binary target
target_link_libraries(ws_core_binary
    PUBLIC

    # "-Wl,-lboost_system,-lpthread"
    ws_core_library

    # Threads::Threads
    ${Boost_LIBRARIES}
)
