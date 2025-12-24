#pragma once

#include "../World.hpp"
#include "../levels/Scheduler.hpp"

class ScheduleManager {
public:
  ScheduleManager(World &w) : world(w) {}

  void resetScheduler() { scheduler.init(); }

  void updateScheduler(float deltaTime) { scheduler.update(deltaTime); }

  Scheduler scheduler;

private:
  World &world;
};
