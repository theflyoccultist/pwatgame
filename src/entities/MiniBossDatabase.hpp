#pragma once

#include <entities/MiniBossSpec.hpp>
#include <entities/MiniBossType.hpp>
#include <lua/LuaWrapper.hpp>
#include <projectiles/ProjectileType.hpp>
#include <projectiles/WeaponSpec.hpp>

#include <unordered_map>

class MiniBossDatabase {
public:
  MiniBossDatabase(LuaWrapper &lua) : lua(lua) {}

  MiniBossDatabase &operator=(const MiniBossDatabase &) = delete;
  MiniBossDatabase &operator=(const MiniBossDatabase &&) = delete;

  void loadFromLua(const char *filename);
  static const MiniBossSpec &get(MiniBossType t);
  static WeaponSpec getWeaponSpec(ProjectileType pt);

private:
  LuaWrapper &lua;

  static inline std::unordered_map<MiniBossType, MiniBossSpec> mbTable;
};
