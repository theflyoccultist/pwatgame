#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include <raylib.h>

class SpawnScheduler {
public:
  SpawnScheduler(World &w) : world(w) {}

  void init() {
    world.enemyManager.init();
    scheduler.init();
  }

  void clearAllEnemies() { world.enemyManager.clearAll(); }

  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void scheduleItems() {
    world.itemManager.populateItems(10, 10);

    scheduler.schedule(15.0f, [&] { world.itemManager.populateItems(2, 5); });

    scheduler.schedule(60.0f, [&] { world.itemManager.populateItems(7, 0); });
  }

  void scheduleEnemies() {
    world.enemyManager.spawnEnemies(EnemyType::SNIPER, 10);

    world.enemyManager.spawnEnemies(EnemyType::ZOMB, 1);

    scheduler.schedule(
        5.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::GODSIP, 4); });

    scheduler.schedule(
        10.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::SWARMER, 5); });

    scheduler.schedule(30.0f, [&] {
      world.enemyManager.spawnEnemies(EnemyType::SWARMER, 25);
    });

    scheduler.schedule(
        50.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::SNIPER, 10); });

    scheduler.schedule(
        55.0f, [&] { world.enemyManager.spawnEnemies(EnemyType::GODSIP, 7); });
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
