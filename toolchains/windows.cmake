# compile:
# cmake -B build-win -DCMAKE_TOOLCHAIN_FILE=toolchains/windows.cmake
# cmake --build build-win

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
