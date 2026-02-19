#include <entities/MiniBossDatabase.hpp>
#include <lua/TypeFromString.hpp>
#include <projectiles/WeaponDatabase.hpp>

#include <expected>
#include <iostream>
#include <string_view>

void MiniBossDatabase::loadFromLua(const char *filename) {
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

        std::cout << "Miniboss Database - Successfully loaded lua script: "
                  << filename << "\n";
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

WeaponSpec MiniBossDatabase::getWeaponSpec(ProjectileType pt) {
  return WeaponDataBase::get(pt);
}
