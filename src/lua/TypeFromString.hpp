#pragma once

#include "../entities/EnemyType.hpp"
#include "../entities/MiniBossType.hpp"
#include "../items/ItemType.hpp"
#include "../projectiles/ProjectileType.hpp"
#include <string_view>

namespace TypeFromString {
inline FoodType foodTypeFromString(std::string_view s) {
  if (s == "buldak")
    return FoodType::BULDAK;
  if (s == "pho")
    return FoodType::PHO;
  if (s == "shinramyun")
    return FoodType::SHINRAMYUN;
  if (s == "tomyum")
    return FoodType::TOMYUM;
  if (s == "yopokki")
    return FoodType::YOPOKKI;

  return FoodType::BULDAK;
}

inline DrinkType drinkTypeFromString(std::string_view s) {
  if (s == "bobatea")
    return DrinkType::BOBATEA;
  if (s == "calpis")
    return DrinkType::CALPIS;
  if (s == "icecoffee")
    return DrinkType::ICECOFFEE;
  if (s == "monster")
    return DrinkType::MONSTER;
  if (s == "soju")
    return DrinkType::SOJU;

  return DrinkType::MONSTER;
}

inline WeaponType weaponTypeFromString(std::string_view s) {
  if (s == "straight")
    return WeaponType::STRAIGHT;
  if (s == "uzi")
    return WeaponType::UZI;
  if (s == "rocket")
    return WeaponType::ROCKET;
  if (s == "hellfire")
    return WeaponType::HELLFIRE;
  if (s == "grenade")
    return WeaponType::GRENADE;

  return WeaponType::ROCKET;
}

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
  if (s == "java")
    return MiniBossType::JAVA;
  if (s == "rust")
    return MiniBossType::RUST;

  return MiniBossType::WINDOWS;
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
  if (s == "hellfire")
    return ProjectileType::HELLFIRE;
  if (s == "grenade")
    return ProjectileType::GRENADE;
  if (s == "ie")
    return ProjectileType::INTERNET;
  if (s == "exe")
    return ProjectileType::EXECUTABLE;

  return ProjectileType::ROCKET;
}
} // namespace TypeFromString
