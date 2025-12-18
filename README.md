# Pwatgame: A bullet hell game engine in C++ and Raylib

You will play as PwatPwat, a cute blob cat plush who needs to claim her throne as the cutest one ever! But some jealous enemies are getting on your way. Fight your way throughout different levels, refill your health with drinks, and refill your ammo with food, scattered across the map. Discover different weapons to use and fight different, equally evil mini bosses.

## Features:
- **Game Modes**: 
  Each level has different weapon and enemy data, with slightly increasing difficulty and a different miniboss for each level.

  - **Default Deathless mode**: Complete all four levels at once. Score and ammo persists throughout levels, so try to get the highest score you can. If you run out of health, you will have to restart all over from level 1 again. Access it by selecting "Play Game" in the Main Menu.
  - **Play From Level**: Start from a specific level. Access it by selecting "Select Level" in the Main Menu. If you run out of health, you will simply restart from that level.

- **Music Composed and Arranged by myself**: The sound effects were picked up from opengameart.org, but I composed the soundtrack that you can hear throughout the game. 

- **Lua scripting layer**: allows the editing of Enemy, Projectiles, Mini Boss data, Enemy and Item scheduling without recompiling the game engine, using some simple Lua tables with data. On the C++ side, it is handled using `std::expected` for safety and monadic operation chaining. I also made usage of `Concepts` for Item scheduling.

- **Statically templated cache pools for Enemies, Projectiles and Mini Bosses:** these spawns without heap allocation, allowing optimal performance and prevents the game engine from spawning an excessive amount of objects, therefore preventing frame losses as well.

- **Usage of CMake as a build tool**: for better multi platform compatibility and reliable compilation.

## Building:
- Make sure to have a C++23 compatible compiler. This project was built using GCC 14.2 across my Trixie Debian and Arch Linux computers.
- Make sure to have the Lua and Raylib C libraries installed on your machine.

Use the Linux_build.sh script to compile on Linux. This shell script will automatically create a new `build/` folder and generate a `pwatgame` binary that is compatible with Unix systems.
