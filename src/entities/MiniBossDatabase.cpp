#include "MiniBossDatabase.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "MiniBossSpec.hpp"
#include "MiniBossType.hpp"
#include <iostream>

static const MiniBossSpec miniBossTable[] = {
    {15, 1000},
    {150, 100},
};

const MiniBossSpec &MiniBossDatabase::get(MiniBossType type) {
  return miniBossTable[static_cast<int>(type)];
}

ProjectileType MiniBossDatabase::getWeaponType(MiniBossType m) {
  switch (m) {
  case MiniBossType::WINDOWS:
    return ProjectileType::SLOWCANNON;
  case MiniBossType::LISP:
    return ProjectileType::STRAIGHT;
  default:
    std::cerr << "MiniBossDatabase getWeaponType : unknown MiniBoss type\n";
    return ProjectileType::ROCKET;
  }
}

WeaponSpec MiniBossDatabase::getWeaponSpec(MiniBossType m) {
  ProjectileType pt = getWeaponType(m);
  return WeaponDataBase::get(pt);
}
