cmake_minimum_required(VERSION 3.5)

project(ws_server_library)

get_filename_component(PARENT_DIR ../ ABSOLUTE)

# This is how the compiler can find and link the definitions in the cpp files
add_library(ws_server_library STATIC
    "include/HELLO/Hello.cpp"
    ${PARENT_DIR}/WS_CORE/include/SERVERSTUFF/ServerStuff.cpp
)

# This is how the compiler finds the .h files in our includes
target_include_directories(ws_server_library
    PUBLIC
    ${PARENT_DIR}
)

# Add an executable with the above sources
add_executable(ws_server_binary
    main.cpp
) # ###########################################################

# Create an executable
# ###########################################################

# link the new ws_server_library target with the ws_server_binary target
target_link_libraries(ws_server_binary
    PRIVATE
    ws_server_library
)
