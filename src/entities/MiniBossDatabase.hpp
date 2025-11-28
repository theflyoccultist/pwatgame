#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "MiniBossSpec.hpp"
#include "MiniBossType.hpp"

class MiniBossDatabase {
public:
  static const MiniBossSpec &get(MiniBossType t);

  static ProjectileType getWeaponType(MiniBossType m);
  static WeaponSpec getWeaponSpec(MiniBossType m);
};
