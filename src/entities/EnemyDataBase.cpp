#include "EnemyDatabase.hpp"
#include "../lua/TypeFromString.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "EnemySpec.hpp"
#include "EnemyType.hpp"
#include <expected>
#include <iostream>
#include <string_view>

void EnemyDatabase::loadFromLua(const char *filename) {
  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("Enemies")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          EnemyType type;
          type = lua.getString("type")
                     .transform([&](const std::string_view &s) {
                       return TypeFromString::enemyTypeFromString(s);
                     })
                     .value_or(EnemyType::ZOMB);

          EnemySpec spec;
          spec.speed = lua.getNumber("speed").value_or(0.0f);
          spec.totalHP = lua.getInt("hp").value_or(1);

          eTable[type] = spec;

          lua_pop(lua.getState(), 1);
        }

        std::cout << "Enemy Database - Successfully loaded lua script: "
                  << filename << "\n";
        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected enemy table: " << e << "\n";
        return std::expected<void, LuaError>();
      });
}

const EnemySpec &EnemyDatabase::get(EnemyType e) { return eTable.at(e); };

ProjectileType EnemyDatabase::getWeaponType(EnemyType e) {
  switch (e) {
  case EnemyType::SWARMER:
    return ProjectileType::UZI;
  case EnemyType::SNIPER:
    return ProjectileType::LONGRANGE;
  case EnemyType::GODSIP:
    return ProjectileType::STRAIGHT;
  case EnemyType::ZOMB:
    return ProjectileType::SLOWCANNON;
  case EnemyType::MONITOR:
    return ProjectileType::ROCKET;
  default:
    return ProjectileType::UZI;
  }
}

WeaponSpec EnemyDatabase::getWeaponSpec(EnemyType e) {
  ProjectileType pt = getWeaponType(e);
  return WeaponDataBase::get(pt);
}
