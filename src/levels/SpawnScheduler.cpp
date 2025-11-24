#include "SpawnScheduler.hpp"
#include <expected>
#include <iostream>
#include <raylib.h>
#include <string_view>
#include <vector>

void SpawnScheduler::scheduleMusic() {
  auto &audio = AudioSystem::instance();
  audio.music->stopMusic();
  audio.music->playLevelTrack();

  scheduler.schedule(128.0f, [&] {
    audio.music->stopMusic();
    audio.music->playBossMusic();
  });
}

void SpawnScheduler::loadScript(const char *filename) {
  lua.runFile(filename).or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });
}

void SpawnScheduler::scheduleItems() {
  struct spawnItem {
    ItemCategory cat;
    Vector2 pos;
    double delay;
  };

  std::vector<spawnItem> itemSpawnData{};

  lua.getTable("ItemSpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnItem item;
          item.cat = lua.getString("type")
                         .transform([&](const std::string_view &s) {
                           return lua.itemTypeFromString(s);
                         })
                         .value_or(ItemCategory::Drink);

          item.pos.x = static_cast<float>(lua.getInt("x").value_or(0));
          item.pos.y = static_cast<float>(lua.getInt("y").value_or(0));
          item.delay = lua.getNumber("delay").value_or(0.0);

          itemSpawnData.push_back(item);

          lua_pop(lua.getState(), 1);
        }

        return {};
      })
      .or_else([](LuaError e) {
        std::cerr << "Expected item table: " << e << "\n";
        return std::expected<void, LuaError>();
      });

  for (const auto &spawn : itemSpawnData) {
    scheduler.schedule(spawn.delay, [c = spawn.cat, p = spawn.pos, this] {
      world.itemManager.populateItems(c, p);
    });
  }
}

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
                            return lua.enemyTypeFromString(s);
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
    scheduler.schedule(wave.delay,
                       [type = wave.type, n = wave.numEnemies, this] {
                         world.enemyManager.spawnEnemies(type, n);
                       });
  }
}

void SpawnScheduler::scheduleMiniBoss() {
  for (int i = 0; i < 6; i++) {
    scheduler.schedule(122.0f + static_cast<float>(i), [&] {
      world.enemyManager.spawnEnemies(EnemyType::MONITOR);
    });
  }

  scheduler.schedule(128.0f, [&] {
    world.minibossManager.spawnMiniBoss(MiniBossType::WINDOWS);
  });
}

void SpawnScheduler::updateScheduler(float deltaTime) {
  scheduler.update(deltaTime);
}
