#!/usr/bin/env bash

mkdir -p build
cmake -B build -DCMAKE_TOOLCHAIN_FILE=toolchains/linux.cmake
cmake --build build
