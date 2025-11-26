#pragma once

#include "MiniBossSpec.hpp"
#include "MiniBossType.hpp"

class MiniBossDatabase {
public:
  static ProjectileType getWeaponType(MiniBossType m);
  static WeaponSpec getWeaponSpec(MiniBossType m);

  // TODO: Put MiniBoss Data here instead of in each class
  static const MiniBossSpec &get(MiniBossType t);
};
