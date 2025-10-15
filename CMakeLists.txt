cmake_minimum_required(VERSION 3.16)
project(pwatman CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER_VERSION 12)

include_directories(include)

file(GLOB_RECURSE SOURCES src/*.cpp sound/*.cpp)
add_executable(pwatman ${SOURCES})

find_package(raylib REQUIRED)
target_link_libraries(pwatman PRIVATE raylib)

# Normal
target_compile_options(pwatman PRIVATE -Wall -Wextra -Wpedantic)

# For leaks and segfaults
# target_compile_options(pwatman PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
# target_link_options(pwatman PRIVATE -fsanitize=address)
