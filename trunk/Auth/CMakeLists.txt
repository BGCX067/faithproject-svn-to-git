
cmake_minimum_required(VERSION 2.8)

project(Faith)

set(EXECUTABLE_OUTPUT_PATH build)
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++0x -Wall -Wextra -g -DUNIX")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -UDEBUG -DNDEBUG -DUNIX")
set(CMAKE_BUILD_TYPE "DEBUG")

file(GLOB server_srcs
    "*.cpp"
)

add_executable(fserver
    ${server_srcs}
)

target_link_libraries(fserver
    wt
    wtdbo
    wthttp
    wtdbosqlite3
    boost_signals
    boost_system
)

