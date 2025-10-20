#!/usr/bin/env bash

rm -f -R build
mkdir -p build
cmake -B build -DCMAKE_TOOLCHAIN_FILE=toolchains/linux.cmake
cmake --build build

git ls-files '*.cpp' '*.hpp' | xargs wc -l
