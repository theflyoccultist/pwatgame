#pragma once

#include <raylib.h>

class Game {
public:
  void run();

  static inline float deltaTime = 0.0f;

  enum class GameState { MainMenu, Restarting, Playing, Paused, Options };
  static inline GameState currentState = GameState::MainMenu;
};
