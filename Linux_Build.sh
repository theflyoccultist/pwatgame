#!/usr/bin/env bash

rm -f -R build
mkdir -p build
cmake -B build -DCMAKE_TOOLCHAIN_FILE=toolchains/linux.cmake
cmake --build build

printf "C++ LOC :\n"
git ls-files '*.cpp' '*.hpp' | xargs wc -l | tail -n 1
printf "lua LOC :\n"
git ls-files '*.lua' | xargs wc -l | tail -n 1
