#pragma once

#include "../World.hpp"
#include "../levels/Scheduler.hpp"

class ScheduleManager {
public:
  ScheduleManager(World &w) : world(w) {}

  void resetScheduler() { scheduler.init(); }

  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void updateProjectiles(float deltaTime) {
    world.projectileManager.update(deltaTime);
    world.projectileManager.draw();
  }

  void updateScheduler(float deltaTime) { scheduler.update(deltaTime); }

  Scheduler scheduler;

private:
  World &world;
};
