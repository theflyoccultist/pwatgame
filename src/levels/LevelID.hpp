#pragma once

#include <cstdint>

enum class LevelID : uint8_t { Level1, Level2, Level3, Level4 };

inline LevelID &operator++(LevelID &level, int) {
  const int i = static_cast<int>(level) + 1;
  level = static_cast<LevelID>((i) % 4);
  return level;
}
