cmake_minimum_required(VERSION 3.16)
project(pwatgame CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER_VERSION 12)

include_directories(include)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(pwatgame ${SOURCES})

find_package(raylib REQUIRED)
target_link_libraries(pwatgame PRIVATE raylib)

# Normal
target_compile_options(pwatgame PRIVATE -Wall -Wextra -Wpedantic)

# For leaks and segfaults
# target_compile_options(pwatgame PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
# target_link_options(pwatgame PRIVATE -fsanitize=address)
