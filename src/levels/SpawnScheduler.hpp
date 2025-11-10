#include "../World.hpp"
#include "../levels/Scheduler.hpp"
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
        {0.f, 2, 5},   {35.2f, 0, 7}, {60.f, 7, 0},
        {70.1f, 1, 8}, {73.8f, 4, 2}, {85.9f, 1, 5},
    };

    for (const auto &spawn : itemSpawnData) {
      scheduler.schedule(spawn.delay, [f = spawn.food, d = spawn.drink, this] {
        world.itemManager.populateItems(f, d);
      });
    }
  }

  void scheduleEnemies() {
    struct spawnEnemy {
      float delay;
      EnemyType type;
      int numEnemies;
    };

    const std::vector<spawnEnemy> enemySpawnData = {
        {0.f, EnemyType::SNIPER, 10},   {0.7f, EnemyType::ZOMB, 8},
        {5.2f, EnemyType::GODSIP, 4},   {10.f, EnemyType::SWARMER, 5},
        {22.1f, EnemyType::ZOMB, 15},   {30.f, EnemyType::SWARMER, 15},
        {50.1f, EnemyType::SNIPER, 10}, {52.f, EnemyType::SWARMER, 15},
        {55.4f, EnemyType::GODSIP, 7},  {90.f, EnemyType::ZOMB, 7},
        {105.f, EnemyType::GODSIP, 3},  {120.f, EnemyType::SWARMER, 7},
    };

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
