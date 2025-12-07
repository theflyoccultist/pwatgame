#pragma once

#include <cstdint>

enum class LevelID : uint8_t { Level1, Level2, Level3, Level4 };

inline LevelID &operator++(LevelID &level, int) {
  const int i = static_cast<int>(level) + 1;
  level = static_cast<LevelID>((i) % 4);
  return level;
}

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
