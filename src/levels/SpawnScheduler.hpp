#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include <array>
#include <raylib.h>
#include <vector>

class SpawnScheduler {
public:
  SpawnScheduler(World &w) : world(w) {}

  void init() { world.enemyManager.init(); }

  void resetScheduler() { scheduler.init(); }
  void clearAllEnemies() { world.enemyManager.clearAll(); }
  void clearALlItems() { world.itemManager.clearAll(); }
  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void scheduleItems() {
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

  void schedulePowerUpItems() {
    struct spawnPowerup {
      float delay;
      int weapon;
    };

    const std::vector<spawnPowerup> powerupSpawnData = {
        {70.0f, 1},
    };

    for (const auto &spawn : powerupSpawnData) {
      scheduler.schedule(spawn.delay, [w = spawn.weapon, this] {
        world.itemManager.populatePowerUps(w);
      });
    }
  }

  // for later when i'll have different game levels:
  // static const std::unordered_set<EnemyType> level1Enemies = {
  //     EnemyType::SNIPER,
  //     EnemyType::ZOMB,
  //     ...
  // };

  void scheduleEnemies() {
    struct spawnEnemy {
      float delay;
      EnemyType type;
      int numEnemies;
    };

    std::array<spawnEnemy, 25> enemySpawnData{};
    for (auto &s : enemySpawnData) {
      s = {Random::rangeFloat(0.0f, 200.0f),
           static_cast<EnemyType>(
               Random::rangeInt(0, (int)EnemyType::COUNT - 1)),
           Random::rangeInt(3, 7)};
    }

    world.enemyManager.spawnEnemies(EnemyType::SNIPER, Random::rangeInt(3, 8));
    world.enemyManager.spawnEnemies(EnemyType::ZOMB, Random::rangeInt(3, 8));

    for (const auto &spawn : enemySpawnData) {
      scheduler.schedule(spawn.delay,
                         [type = spawn.type, n = spawn.numEnemies, this] {
                           world.enemyManager.spawnEnemies(type, n);
                         });
    }
  }

  void updateScheduler(float deltaTime) { scheduler.update(deltaTime); }

  void updateItems(const PlayerState &pwatState) {
    world.itemManager.updateItems(pwatState.position, pwatState.playerSize);
    world.itemManager.drawItems(ItemCategory::Food);
    world.itemManager.drawItems(ItemCategory::Drink);
    world.itemManager.drawItems(ItemCategory::Weapon);
  }

  void updateProjectiles(float deltaTime) {
    world.projectileManager.update(deltaTime);
    world.projectileManager.draw();
  }

  void updateEnemies(float deltaTime, const PlayerState &pwatState) {
    auto bullets = world.projectileManager.view();
    world.enemyManager.updateAll(deltaTime, pwatState, bullets);
    world.enemyManager.drawAll();
  }

private:
  World &world;
  Scheduler scheduler;
};
