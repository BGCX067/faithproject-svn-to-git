
cmake_minimum_required(VERSION 2.8)

project(Faith)

set(CMAKE_CXX_FLAGS_DEBUG "-std=c++0x -Wall -Wextra -g -DUNIX")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -UDEBUG -DNDEBUG -DUNIX")
set(CMAKE_BUILD_TYPE "DEBUG")

include_directories(
    src
)

file(GLOB faith_srcs
    "src/*.cpp"
    "src/db/*.cpp"
)

add_executable(faith_server
    ${faith_srcs}
)

target_link_libraries(faith_server
    wt
    wtdbo
    wthttp
    wtdbosqlite3
    boost_signals
    boost_system
)

