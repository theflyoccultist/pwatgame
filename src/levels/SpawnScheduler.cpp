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

  const std::vector<spawnItem> itemSpawnData = {
      {0.f, 7, 2},   {35.2f, 0, 7}, {60.f, 7, 0},
      {70.1f, 1, 8}, {73.8f, 4, 2}, {85.9f, 1, 5},
  };

  for (const auto &spawn : itemSpawnData) {
    scheduler.schedule(spawn.delay, [f = spawn.food, d = spawn.drink, this] {
      world.itemManager.populateItems(f, d);
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

    float minRangeF = std::lerp(0.0f, 140.0f, t);
    float maxRangeF = std::lerp(70.0f, 200.0f, t);

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

void SpawnScheduler::updateScheduler(float deltaTime) {
  scheduler.update(deltaTime);
  if (world.enemyManager.enemyCount <= 2) {
    world.enemyManager.spawnEnemies(static_cast<EnemyType>(Random::rangeInt(
                                        0, (int)level1Enemies.size() - 1)),
                                    Random::rangeInt(3, 7));
  }
}
