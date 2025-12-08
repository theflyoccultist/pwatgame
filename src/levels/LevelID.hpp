#pragma once

#include <cstdint>
#include <ostream>

enum class LevelID : uint8_t { Level1, Level2, Level3, Level4 };

inline LevelID &operator++(LevelID &level, int) {
  const int i = static_cast<int>(level) + 1;
  level = static_cast<LevelID>((i) % 4);
  return level;
}

inline std::ostream &operator<<(std::ostream &os, LevelID &level) {
  switch (level) {
  case LevelID::Level1:
    os << "level 1";
    break;
  case LevelID::Level2:
    os << "level 2";
    break;
  case LevelID::Level3:
    os << "level 3";
    break;
  case LevelID::Level4:
    os << "level 4";
    break;
  }
  return os;
}
