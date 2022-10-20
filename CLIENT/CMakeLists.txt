cmake_minimum_required(VERSION 3.5)

project(ws_client_library)

find_package(Boost 1.80.0 REQUIRED)

get_filename_component(PARENT_DIR ../ ABSOLUTE)

# This is how the compiler can find and link the definitions in the cpp files
add_library(ws_client_library STATIC
    "include/HELLO/Hello.cpp"
    ${PARENT_DIR}/WS_CORE/include/SERVERSTUFF/ServerStuff.cpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# This is how the compiler finds the .h files in our includes
target_include_directories(ws_client_library
    PUBLIC
    ${PARENT_DIR}
    ${Boost_INCLUDE_DIRS}
    PRIVATE
)

# Add an executable with the above sources
add_executable(ws_client_binary
    main.cpp
) # ###########################################################

# Create an executable
# ###########################################################

# link the new ws_client_library target with the ws_client_binary target
target_link_libraries(ws_client_binary
    PUBLIC
    ws_client_library
    ${Boost_LIBRARIES}
)
