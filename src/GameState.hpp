#pragma once

#include <cstdint>

enum class GameState : uint8_t {
  MainMenu,
  Restarting,
  NewLevel,
  Playing,
  Paused,
  Options,
  Lost,
  Won,
  NextLevel,
  ShowCredits,
};
