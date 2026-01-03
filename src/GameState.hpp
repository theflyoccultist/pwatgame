#pragma once

#include <cstdint>

enum class GameState : uint8_t {
  MainMenu,
  LevelSelection,
  DisplayHelp,
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
