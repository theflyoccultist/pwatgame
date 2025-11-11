#pragma once

#include "World.hpp"
#include <raylib.h>

class Game {
public:
  void run();

  static inline float deltaTime = 0.0f;

  enum class GameState { MainMenu, Restarting, Playing, Paused, Options, Lost };
  static inline GameState currentState = GameState::MainMenu;

private:
  World world;
};
