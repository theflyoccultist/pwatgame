#pragma once

#include "../lua/LuaWrapper.hpp"
#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "EnemySpec.hpp"
#include "EnemyType.hpp"
#include <unordered_map>

class EnemyDatabase {
public:
  static void loadFromLua(LuaWrapper &lua, const char *filename);
  static const EnemySpec &get(EnemyType e);

  static ProjectileType getWeaponType(EnemyType e);
  static WeaponSpec getWeaponSpec(EnemyType e);

private:
  static inline std::unordered_map<EnemyType, EnemySpec> eTable;
};
