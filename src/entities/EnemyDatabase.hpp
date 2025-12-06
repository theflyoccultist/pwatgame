#pragma once

#include "../lua/LuaWrapper.hpp"
#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include "EnemySpec.hpp"
#include "EnemyType.hpp"
#include <unordered_map>

class EnemyDatabase {
public:
  EnemyDatabase(LuaWrapper &lua) : lua(lua) {}

  void loadFromLua(const char *filename);
  static const EnemySpec &get(EnemyType e);

  static ProjectileType getWeaponType(EnemyType e);
  static WeaponSpec getWeaponSpec(EnemyType e);

private:
  LuaWrapper &lua;

  static inline std::unordered_map<EnemyType, EnemySpec> eTable;
};
