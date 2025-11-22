#pragma once

#include "World.hpp"
#include "levels/SpawnScheduler.hpp"
#include <cstdint>
#include <raylib.h>

class Game {
public:
  void run();

  static inline float deltaTime = 0.0f;

  enum class GameState : uint8_t {
    MainMenu,
    Restarting,
    Playing,
    Paused,
    Options,
    Lost,
    Won,
  };

  static inline GameState currentState = GameState::MainMenu;

private:
  World world;
};
