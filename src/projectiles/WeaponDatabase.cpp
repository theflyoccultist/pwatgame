#include <expected>
#include <iostream>

#include <lua/TypeFromString.hpp>
#include <projectiles/WeaponDatabase.hpp>
#include <string_view>

void WeaponDataBase::loadFromLua(const char *filename) {
  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("Weapons")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          ProjectileType type;
          type = lua.getString("type")
                     .transform([&](const std::string_view &s) {
                       return TypeFromString::projTypeFromString(s);
                     })
                     .value_or(ProjectileType::ROCKET);

          WeaponSpec spec;
          spec.speed = lua.getInt("speed").value_or(0);
          spec.fireRate = lua.getNumber("fireRate").value_or(1.0f);
          spec.size = lua.getNumber("size").value_or(1.0f);
          spec.lifetime = lua.getNumber("lifetime").value_or(1.0f);
          spec.damage = lua.getInt("damage").value_or(1);

          wTable[type] = spec;

          lua_pop(lua.getState(), 1);
        }

        std::cout << "Weapon Database - Successfully loaded lua script: "
                  << filename << "\n";
        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected weapon table: " << e << "\n";
        return std::expected<void, LuaError>();
      });
}

const WeaponSpec &WeaponDataBase::get(ProjectileType type) {
  return wTable.at(type);
}
