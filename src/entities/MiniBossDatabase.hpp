#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "MiniBossType.hpp"

struct MiniBossSpec {
  int maxHealth;
  float speed;
  ProjectileType weapon;
  WeaponSpec weaponSpec;
};

class MiniBossDatabase {
public:
  static ProjectileType getWeaponType(MiniBossType m);
  static WeaponSpec getWeaponSpec(MiniBossType m);
};
