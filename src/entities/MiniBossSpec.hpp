#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"

struct MiniBossSpec {
  int maxHealth;
  float speed;
  ProjectileType weapon;
  WeaponSpec weaponSpec;
};
