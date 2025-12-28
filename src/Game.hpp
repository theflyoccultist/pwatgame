#pragma once

#include "GameState.hpp"
#include "World.hpp"
#include "lua/LuaWrapper.hpp"
#include <raylib.h>

class Game {
public:
  void run();

  float deltaTime;

  static inline GameState currentState = GameState::MainMenu;

private:
  World world;
  LuaWrapper lua;
};
