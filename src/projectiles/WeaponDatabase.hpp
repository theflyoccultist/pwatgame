#pragma once

#include <lua/LuaWrapper.hpp>
#include <projectiles/ProjectileType.hpp>
#include <projectiles/WeaponSpec.hpp>

#include <unordered_map>

class WeaponDataBase {
public:
  WeaponDataBase(LuaWrapper &lua) : lua(lua) {}

  WeaponDataBase &operator=(const WeaponDataBase &) = delete;
  WeaponDataBase &operator=(const WeaponDataBase &&) = delete;

  void loadFromLua(const char *filename);
  static const WeaponSpec &get(ProjectileType t);

private:
  static inline std::unordered_map<ProjectileType, WeaponSpec> wTable;
  LuaWrapper &lua;
};
