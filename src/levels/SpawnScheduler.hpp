#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include "../lua/LuaWrapper.hpp"
#include <raylib.h>

class SpawnScheduler {
public:
  SpawnScheduler(LuaWrapper &lua, World &w) : lua(lua), world(w) {}

  void initEnemies() {
    world.enemyManager.init();
    world.minibossManager.init();
  }

  void resetScheduler() { scheduler.init(); }

  void clearAllEnemies() {
    world.enemyManager.clearAll();
    world.minibossManager.clearAll();
  }

  void clearAllItems() { world.itemManager.clearAll(); }
  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void scheduleMusic();
  void scheduleItems();
  void schedulePowerUpItems();
  void scheduleEnemies();
  void scheduleMiniBoss();

  void updateScheduler(float deltaTime);

  void updateItems(const PlayerState &pwatState) {
    world.itemManager.updateItems(pwatState.position,
                                  (float)pwatState.playerSize);
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

  bool updateMiniBoss(float deltaTime, const PlayerState &pwatState) {
    auto bullets = world.projectileManager.view();
    if (world.minibossManager.updateAll(deltaTime, pwatState, bullets))
      return true;

    world.minibossManager.drawAll();
    return false;
  }

private:
  LuaWrapper &lua;
  World &world;
  Scheduler scheduler;
};
