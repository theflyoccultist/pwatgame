#pragma once

#include <raylib.h>

#pragma once

class Game {
public:
  void run();
  static constexpr int screenWidth = 800;
  static constexpr int screenHeight = 800;

  static inline float deltaTime = 0.0f;

  enum class GameState { MainMenu, Playing, Paused, Options };
  static inline GameState currentState = GameState::MainMenu;
};
