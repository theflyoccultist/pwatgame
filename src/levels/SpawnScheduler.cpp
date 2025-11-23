#include "SpawnScheduler.hpp"
#include <expected>
#include <iostream>
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

void SpawnScheduler::scheduleItems() {
  struct spawnItem {
    int food;
    int drink;
    double delay;
  };

  std::vector<spawnItem> itemSpawnData{};

  lua.runFile("../scripts/itemspawn.lua").or_else([](LuaError e) {
    std::cerr << e << "\n";
    return std::expected<void, LuaError>();
  });

  lua.getTable("ItemSpawns")
      .and_then([&](void) -> LuaResultT<void> {
        int len = (int)lua_rawlen(lua.getState(), -1);

        for (int i = 1; i <= len; i++) {
          lua_rawgeti(lua.getState(), -1, i);

          spawnItem item;
          item.food = static_cast<int>(lua.getInt("food").value_or(0));
          item.drink = static_cast<int>(lua.getInt("drink").value_or(0));
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
    scheduler.schedule(spawn.delay, [f = spawn.food, d = spawn.drink, this] {
      world.itemManager.populateItems({f, d});
    });
  }
}

void SpawnScheduler::schedulePowerUpItems() {
  struct spawnPowerup {
    float delay;
    int weapon;
  };

  const std::vector<spawnPowerup> powerupSpawnData = {
      {78.0f, 1},
      {115.0f, 1},
  };

  for (const auto &spawn : powerupSpawnData) {
    scheduler.schedule(spawn.delay, [w = spawn.weapon, this] {
      world.itemManager.populatePowerUps(w);
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

  lua.runFile("../scripts/enemyspawn.lua").or_else([](LuaError e) {
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

  scheduler.schedule(
      128.0f, [&] { world.minibossManager.spawnMiniBoss(BossType::WINDOWS); });
}

void SpawnScheduler::updateScheduler(float deltaTime) {
  scheduler.update(deltaTime);
}
