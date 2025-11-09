#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include <raylib.h>

class SpawnScheduler {
public:
  SpawnScheduler(World &w) : world(w) {}

  void init() { world.enemyManager.init(); }

  void resetScheduler() { scheduler.init(); }
  void clearAllEnemies() { world.enemyManager.clearAll(); }
  void clearALlItems() { world.itemManager.clearAll(); }
  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void scheduleItems() {
    world.itemManager.populateItems(10, 10);

    scheduler.schedule(15.0f, [&] { world.itemManager.populateItems(2, 5); });

    scheduler.schedule(60.0f, [&] { world.itemManager.populateItems(7, 0); });

    scheduler.schedule(70.0f, [&] { world.itemManager.populateItems(1, 8); });

    scheduler.schedule(80.0f, [&] { world.itemManager.populateItems(1, 5); });
  }

  void scheduleEnemies() {
    world.enemyManager.spawnEnemies(EnemyType::SNIPER, 10);

    world.enemyManager.spawnEnemies(EnemyType::ZOMB, 8);

    scheduler.schedule(
        5.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::GODSIP, 4); });

    scheduler.schedule(
        10.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::SWARMER, 5); });

    scheduler.schedule(
        22.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::ZOMB, 15); });

    scheduler.schedule(30.0f, [&] {
      world.enemyManager.spawnEnemies(EnemyType::SWARMER, 15);
    });

    scheduler.schedule(
        50.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::SNIPER, 10); });

    scheduler.schedule(52.0f, [&] {
      world.enemyManager.spawnEnemies(EnemyType::SWARMER, 15);
    });

    scheduler.schedule(
        55.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::GODSIP, 7); });

    scheduler.schedule(
        90.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::ZOMB, 7); });

    scheduler.schedule(
        105.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::GODSIP, 3); });

    scheduler.schedule(120.0f, [&] {
      world.enemyManager.spawnEnemies(EnemyType::SWARMER, 7);
    });
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
