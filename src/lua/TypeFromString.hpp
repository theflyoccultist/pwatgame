#pragma once

#include "../entities/EnemyType.hpp"
#include "../entities/MiniBossType.hpp"
#include "../items/ItemType.hpp"
#include "../projectiles/ProjectileType.hpp"
#include <string_view>

namespace TypeFromString {
inline EnemyType enemyTypeFromString(std::string_view s) {
  if (s == "godsip")
    return EnemyType::GODSIP;
  if (s == "monitor")
    return EnemyType::MONITOR;
  if (s == "sniper")
    return EnemyType::SNIPER;
  if (s == "swarmer")
    return EnemyType::SWARMER;
  if (s == "zomb")
    return EnemyType::ZOMB;

  return EnemyType::ZOMB;
}

inline MiniBossType mbTypeFromString(std::string_view s) {
  if (s == "windows")
    return MiniBossType::WINDOWS;
  if (s == "lisp")
    return MiniBossType::LISP;

  return MiniBossType::WINDOWS;
}

inline ItemCategory itemTypeFromString(std::string_view s) {
  if (s == "food")
    return ItemCategory::Food;
  if (s == "drink")
    return ItemCategory::Drink;
  if (s == "weapon")
    return ItemCategory::Weapon;

  return ItemCategory::Food;
}

inline ProjectileType projTypeFromString(std::string_view s) {
  if (s == "longrange")
    return ProjectileType::LONGRANGE;
  if (s == "slowcannon")
    return ProjectileType::SLOWCANNON;
  if (s == "straight")
    return ProjectileType::STRAIGHT;
  if (s == "uzi")
    return ProjectileType::UZI;
  if (s == "rocket")
    return ProjectileType::ROCKET;

  return ProjectileType::ROCKET;
}
} // namespace TypeFromString
