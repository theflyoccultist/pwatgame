#pragma once

#include <levels/LevelID.hpp>

int displayCurrentLevel(LevelID level) {
  switch (level) {
  case LevelID::Level1:
    return 1;
  case LevelID::Level2:
    return 2;
  case LevelID::Level3:
    return 3;
  case LevelID::Level4:
    return 4;
  default:
    return 0;
  }
}
