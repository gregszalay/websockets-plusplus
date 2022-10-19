cmake_minimum_required(VERSION 3.5)

project(ws_core_library)

find_package(Threads REQUIRED)

# ###########################################################
# Create a library
# ###########################################################
# find_package(Boost 1.40.0 REQUIRED system)
# FIND_PACKAGE(Boost 1.42.0 REQUIRED COMPONENTS system thread regex)

# IF(Boost_FOUND)
# INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
# LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
# ENDIF(Boost_FOUND)

# Include our own module path. This makes #include "x.h"
# work in project subfolders to include the main directory headers.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Generate the static library from the library sources
add_library(ws_core_library STATIC
    "include/HELLO/Hello.cpp"
    "include/SERVERSTUFF/ServerStuff.cpp"
)
target_include_directories(ws_core_library
    PUBLIC
    ${PROJECT_SOURCE_DIR}
)

# ###########################################################
# Create an executable
# ###########################################################

# Add an executable with the above sources
add_executable(ws_core_binary
    main.cpp
)

# link the new ws_core_library target with the ws_core_binary target
target_link_libraries(ws_core_binary
    PRIVATE
    ws_core_library
    Threads::Threads
)
