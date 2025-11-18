#include "SpawnScheduler.hpp"
#include <array>
#include <cmath>
#include <vector>

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

void SpawnScheduler::scheduleEnemies() {
  struct spawnEnemy {
    float delay;
    EnemyType type;
    int numEnemies;
  };

  std::array<spawnEnemy, 25> enemySpawnData{};
  for (size_t i = 0; i < enemySpawnData.size(); i++) {
    float t = static_cast<float>(i) / (enemySpawnData.size() - 1);

    float minRangeF = std::lerp(0.0f, 70.0f, t);
    float maxRangeF = std::lerp(50.0f, 120.0f, t);

    float minRangeI_f = std::lerp(3.0f, 7.0f, t);
    float maxRangeI_f = std::lerp(7.0f, 12.0f, t);

    int minRangeI = static_cast<int>(minRangeI_f);
    int maxRangeI = static_cast<int>(maxRangeI_f);

    enemySpawnData[i] = {Random::rangeFloat(minRangeF, maxRangeF),
                         static_cast<EnemyType>(Random::rangeInt(
                             0, (int)level1Enemies.size() - 1)),
                         Random::rangeInt(minRangeI, maxRangeI)};
  }

  for (const auto &spawn : enemySpawnData) {
    scheduler.schedule(spawn.delay,
                       [type = spawn.type, n = spawn.numEnemies, this] {
                         world.enemyManager.spawnEnemies(type, n);
                       });
  }

  world.enemyManager.spawnEnemies(EnemyType::SNIPER, Random::rangeInt(3, 8));
  world.enemyManager.spawnEnemies(EnemyType::ZOMB, Random::rangeInt(3, 8));
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
  if (world.enemyManager.enemyCount <= 2) {
    world.enemyManager.spawnEnemies(static_cast<EnemyType>(Random::rangeInt(
                                        0, (int)level1Enemies.size() - 1)),
                                    Random::rangeInt(3, 7));
  }
}
