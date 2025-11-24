#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "MiniBossType.hpp"

struct MiniBossSpec {
  int maxHealth;
  float speed;
  ProjectileType weapon;
  WeaponSpec WeaponSpec;
};

class MiniBossDatabase {
public:
  static const MiniBossSpec &get(BossType type);
};
