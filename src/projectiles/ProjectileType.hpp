#pragma once

#include <cstdint>

enum class ProjectileType : uint8_t {
  STRAIGHT,
  LONGRANGE,
  SLOWCANNON,
  ROCKET,
  UZI,
  GRENADE,
  HELLFIRE,
  COUNT
};
