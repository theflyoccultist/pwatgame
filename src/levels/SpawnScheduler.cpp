#include "SpawnScheduler.hpp"
#include "../lua/TypeFromString.hpp"
#include <expected>
#include <iostream>
#include <raylib.h>
#include <string_view>
#include <vector>

void SpawnScheduler::scheduleEnemies(const char *filename) {
  struct spawnEnemy {
    EnemyType type;
    double delay;
    int numEnemies;
  };

  std::vector<spawnEnemy> waves{};

  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("EnemySpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnEnemy wave;
          wave.type = lua.getString("type")
                          .transform([&](const std::string_view &s) {
                            return TypeFromString::enemyTypeFromString(s);
                          })
                          .value_or(EnemyType::ZOMB);

          wave.delay = lua.getNumber("delay").value_or(0.0);

          wave.numEnemies = lua.getInt("numEnemies").value_or(0);

          waves.push_back(wave);

          lua_pop(lua.getState(), 1);
        }

        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected spawn table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (auto &wave : waves) {
    sm.scheduler.schedule(wave.delay,
                          [type = wave.type, n = wave.numEnemies, this] {
                            world.enemyManager.spawnEnemies(type, n);
                          });
  }
}

void SpawnScheduler::scheduleMiniBoss(const char *filename) {
  struct spawnMiniBoss {
    MiniBossType type;
    float delay;
  };

  std::vector<spawnMiniBoss> waves{};

  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("MinibossSpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnMiniBoss wave;

          wave.type = lua.getString("type")
                          .transform([&](const std::string_view &s) {
                            return TypeFromString::mbTypeFromString(s);
                          })
                          .value_or(MiniBossType::LISP);

          wave.delay = lua.getNumber("delay").value_or(200.0f);

          waves.push_back(wave);

          lua_pop(lua.getState(), 1);
        }

        return {};
      })

      .or_else([](LuaError e) {
        std::cerr << "Expected spawn table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (auto &wave : waves) {
    sm.scheduler.schedule(wave.delay, [type = wave.type, this] {
      world.minibossManager.spawnMiniBoss(type);
    });
  }
}
