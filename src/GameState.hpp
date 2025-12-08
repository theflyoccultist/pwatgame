#pragma once

#include <cstdint>

enum class GameState : uint8_t {
  MainMenu,
  LevelSelection,
  Restarting,
  Playing,
  Paused,
  Options,
  Lost,
  Won,
  NextLevel,
  ShowCredits,
};
