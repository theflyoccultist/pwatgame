#pragma once

#include <cstdint>

enum class GameState : uint8_t {
  MainMenu,
  LevelSelection,
  Restarting,
  LevelIntro,
  Playing,
  Paused,
  Options,
  Lost,
  Won,
  NextLevel,
  ShowCredits,
};
