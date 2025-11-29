#include "SpawnScheduler.hpp"
#include "../lua/TypeFromString.hpp"
#include <expected>
#include <iostream>
#include <raylib.h>
#include <string_view>
#include <vector>

void SpawnScheduler::scheduleEnemies() {
  struct spawnEnemy {
    EnemyType type;
    double delay;
    int numEnemies;
  };

  std::vector<spawnEnemy> waves{};

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

          wave.numEnemies =
              static_cast<int>(lua.getInt("numEnemies").value_or(0));

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

void SpawnScheduler::scheduleMiniBoss() {
  for (int i = 0; i < 6; i++) {
    sm.scheduler.schedule(122.0f + static_cast<float>(i), [&] {
      world.enemyManager.spawnEnemies(EnemyType::MONITOR);
    });
  }

  sm.scheduler.schedule(
      128.0f, [&] { world.minibossManager.spawnMiniBoss(MiniBossType::LISP); });
}
