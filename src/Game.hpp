#pragma once

#include <GameState.hpp>
#include <World.hpp>
#include <lua/LuaWrapper.hpp>
#include <raylib.h>

class Game {
public:
  Game &operator=(const Game &) = delete;
  Game &operator=(const Game &&) = delete;

  void run();

  float deltaTime;

  static inline GameState currentState = GameState::MainMenu;

private:
  World world;
  LuaWrapper lua;
};
