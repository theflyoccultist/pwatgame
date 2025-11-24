#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "EnemyType.hpp"

class EnemyDatabase {
public:
  static ProjectileType getWeaponType(EnemyType e);
  static WeaponSpec getWeaponSpec(EnemyType e);
};
