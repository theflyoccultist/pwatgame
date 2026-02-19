#pragma once

#include <entities/EnemySpec.hpp>
#include <entities/EnemyType.hpp>
#include <lua/LuaWrapper.hpp>
#include <projectiles/ProjectileType.hpp>
#include <projectiles/WeaponSpec.hpp>

#include <unordered_map>

class EnemyDatabase {
public:
  EnemyDatabase(LuaWrapper &lua) : lua(lua) {}

  EnemyDatabase &operator=(const EnemyDatabase &) = delete;
  EnemyDatabase &operator=(const EnemyDatabase &&) = delete;

  void loadFromLua(const char *filename);
  static const EnemySpec &get(EnemyType e);

  static WeaponSpec getWeaponSpec(ProjectileType pt);

private:
  LuaWrapper &lua;

  static inline std::unordered_map<EnemyType, EnemySpec> eTable;
};
