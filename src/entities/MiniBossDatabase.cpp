#include "MiniBossDatabase.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "MiniBossType.hpp"
#include <iostream>

// static const MiniBossSpec miniBossTable[] = {
//     {1000, 15, ProjectileType::STRAIGHT,
//      WeaponDataBase::get(ProjectileType::STRAIGHT)},
//
//     {2000, 150, ProjectileType::LONGRANGE,
//      WeaponDataBase::get(ProjectileType::LONGRANGE)},
// };

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
