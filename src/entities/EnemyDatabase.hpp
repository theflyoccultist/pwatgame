#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "EnemySpec.hpp"
#include "EnemyType.hpp"

class EnemyDatabase {
public:
  static const EnemySpec &get(EnemyType e);

  static ProjectileType getWeaponType(EnemyType e);
  static WeaponSpec getWeaponSpec(EnemyType e);
};
