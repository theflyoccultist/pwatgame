#include "MiniBossDatabase.hpp"
#include "../lua/TypeFromString.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "MiniBossSpec.hpp"
#include "MiniBossType.hpp"
#include <expected>
#include <iostream>
#include <string_view>

void MiniBossDatabase::loadFromLua(LuaWrapper &lua, const char *filename) {
  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("MiniBosses")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          MiniBossType type;
          type = lua.getString("type")
                     .transform([&](const std::string_view &s) {
                       return TypeFromString::mbTypeFromString(s);
                     })
                     .value_or(MiniBossType::WINDOWS);

          MiniBossSpec spec;
          spec.speed = lua.getNumber("speed").value_or(0.0f);
          spec.totalHP = lua.getInt("hp").value_or(1);

          mbTable[type] = spec;

          lua_pop(lua.getState(), 1);
        }

        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected MiniBoss table: " << e << "\n";
        return std::expected<void, LuaError>();
      });
}

const MiniBossSpec &MiniBossDatabase::get(MiniBossType type) {
  return mbTable.at(type);
}

ProjectileType MiniBossDatabase::getWeaponType(MiniBossType m) {
  switch (m) {
  case MiniBossType::WINDOWS:
    return ProjectileType::SLOWCANNON;
  case MiniBossType::LISP:
    return ProjectileType::STRAIGHT;
  default:
    std::cerr << "MiniBossDatabase getWeaponType : unknown MiniBoss type\n";
    return ProjectileType::ROCKET;
  }
}

WeaponSpec MiniBossDatabase::getWeaponSpec(MiniBossType m) {
  ProjectileType pt = getWeaponType(m);
  return WeaponDataBase::get(pt);
}
