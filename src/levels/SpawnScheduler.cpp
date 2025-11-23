#include "SpawnScheduler.hpp"
#include <array>
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
    float delay;
    int food;
    int drink;
  };

  std::array<spawnItem, 10> itemSpawnData{};
  for (size_t i = 0; i < itemSpawnData.size(); i++) {
    itemSpawnData[i] = {Random::rangeFloat(0, 120.0f), Random::rangeInt(0, 8),
                        Random::rangeInt(0, 8)};
  }

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

const std::unordered_set<EnemyType> SpawnScheduler::level1Enemies = {
    EnemyType::SWARMER,
    EnemyType::SNIPER,
    EnemyType::ZOMB,
    EnemyType::GODSIP,
};

template <typename T> std::expected<T, LuaError> default_value(T v) {
  return v;
}

void SpawnScheduler::scheduleEnemies() {
  struct spawnEnemy {
    EnemyType type;
    double delay;
    int numEnemies;
  };

  std::vector<spawnEnemy> waves;

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
  // if (world.enemyManager.enemyCount <= 2) {
  //   world.enemyManager.spawnEnemies(static_cast<EnemyType>(Random::rangeInt(
  //                                       0, (int)level1Enemies.size() - 1)),
  //                                   Random::rangeInt(3, 7));
  // }
}
