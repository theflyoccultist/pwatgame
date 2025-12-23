#pragma once

#include <cstdint>
#include <ostream>

enum class GameModes : uint8_t { Dealthless, LevelSelection };

inline std::ostream &operator<<(std::ostream &os, GameModes modes) {
  switch (modes) {
  case GameModes::Dealthless:
    os << "DeathLess";
    break;
  case GameModes::LevelSelection:
    os << "LevelSelection";
    break;
  }

  return os;
}
