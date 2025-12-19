#pragma once

#include <cstdint>
#include <ostream>

enum class ProjectileType : uint8_t {
  STRAIGHT,
  LONGRANGE,
  SLOWCANNON,
  ROCKET,
  UZI,
  GRENADE,
  HELLFIRE,
  INTERNET,
  EXECUTABLE,
  COUNT
};

inline std::ostream &operator<<(std::ostream &os, ProjectileType type) {
  switch (type) {
  case ProjectileType::STRAIGHT:
    os << "STRAIGHT";
    break;
  case ProjectileType::LONGRANGE:
    os << "LONGRANGE";
    break;
  case ProjectileType::SLOWCANNON:
    os << "SLOWCANNON";
    break;
  case ProjectileType::ROCKET:
    os << "ROCKET";
    break;
  case ProjectileType::UZI:
    os << "UZI";
    break;
  case ProjectileType::GRENADE:
    os << "GRENADE";
    break;
  case ProjectileType::HELLFIRE:
    os << "HELLFIRE";
    break;
  case ProjectileType::INTERNET:
    os << "INTERNET EXPLORER";
    break;
  case ProjectileType::EXECUTABLE:
    os << "EXE";
    break;
  default:
    os << "UNKNOWN_PROJECTILE";
    break;
  }
  return os;
}
