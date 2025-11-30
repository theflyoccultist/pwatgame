#pragma once

#include "../lua/LuaWrapper.hpp"
#include "ProjectileType.hpp"
#include "WeaponSpec.hpp"
#include <unordered_map>

class WeaponDataBase {
public:
  static void loadFromLua(LuaWrapper &lua, const char *filename);
  static const WeaponSpec &get(ProjectileType t);

private:
  static inline std::unordered_map<ProjectileType, WeaponSpec> wTable;
};
