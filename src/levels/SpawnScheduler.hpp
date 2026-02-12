#include "../World.hpp"
#include "../levels/ScheduleManager.hpp"
#include "../lua/LuaWrapper.hpp"
#include <raylib.h>

class SpawnScheduler {
public:
  SpawnScheduler(LuaWrapper &lua, World &w, ScheduleManager &sm)
      : lua(lua), world(w), sm(sm) {}

  void loadEnemyTextures() { world.enemyManager.init(); }
  void loadMiniBossTextures() { world.minibossManager.init(); }
  void loadWallTextures() { world.wallManager.init(); }

  void clearAllEnemies() {
    world.enemyManager.clearAll();
    world.enemyManager.resetTimer();
    world.minibossManager.clearAll();
    world.minibossManager.resetTimer();
  }

  void clearAllWalls() {
    world.wallManager.clearAll();
    world.wallManager.resetTimer();
  }

  void scheduleEnemies(const char *filename);
  void scheduleWalls(const char *filename);
  void scheduleMiniBoss(const char *filename);

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

  void updateWalls(float deltaTime, const PlayerState &pwatState) {
    auto bullets = world.projectileManager.view();
    world.wallManager.updateAll(deltaTime, pwatState, bullets);
    world.wallManager.drawAll();
  }

private:
  LuaWrapper &lua;
  World &world;
  ScheduleManager &sm;
};
