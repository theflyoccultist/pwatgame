## Pwatgame: A bullet hell game engine in C++ and Raylib

### Features:
- **Lua scripting layer**: allows the editing of Enemy, Projectiles, Mini boss data, enemy and item spawning without recompiling the game engine. It uses `std::expected` for error handling and monadic operation chaining.

- **Statically templated cache pools for Enemies, Projectiles and Minibosses:** allows stack allocation, optimal performance and prevents the game engine from spawning an excessive amount of them, therefore preventing frame lags as well.

- **Usage of CMake as a build tool**: for better multi platform compatibility and reliable compilation.

### Building:
- Make sure to have a C++23 compatible compiler. This project was built using GCC 14.2 on Trixie Debian and Arch Linux.
- Make sure to have the Lua and Raylib libraries installed on your machine.

Use the Linux_build.sh script to compile on Linux. This shell script will automatically create a new `build/` folder and generate a `pwatgame` binary that is compatible with Unix systems.
