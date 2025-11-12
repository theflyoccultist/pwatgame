#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include <raylib.h>
#include <unordered_set>

class SpawnScheduler {
public:
  SpawnScheduler(World &w) : world(w) {}

  void init() { world.enemyManager.init(); }

  void resetScheduler() { scheduler.init(); }
  void clearAllEnemies() { world.enemyManager.clearAll(); }
  void clearALlItems() { world.itemManager.clearAll(); }
  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void scheduleItems();
  void schedulePowerUpItems();
  void scheduleEnemies();

  void updateScheduler(float deltaTime);

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
  static const std::unordered_set<EnemyType> level1Enemies;
};
