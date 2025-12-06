#pragma once

#include "../lua/LuaWrapper.hpp"
#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "MiniBossSpec.hpp"
#include "MiniBossType.hpp"
#include <unordered_map>

class MiniBossDatabase {
public:
  MiniBossDatabase(LuaWrapper &lua) : lua(lua) {}

  void loadFromLua(const char *filename);
  static const MiniBossSpec &get(MiniBossType t);

  static ProjectileType getWeaponType(MiniBossType m);
  static WeaponSpec getWeaponSpec(MiniBossType m);

private:
  LuaWrapper &lua;

  static inline std::unordered_map<MiniBossType, MiniBossSpec> mbTable;
};
