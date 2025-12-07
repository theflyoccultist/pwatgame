#pragma once

#include <cstdint>

enum class GameState : uint8_t {
  MainMenu,
  Restarting,
  Playing,
  Paused,
  Options,
  Lost,
  Won,
  NextLevel,
};
