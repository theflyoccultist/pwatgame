#pragma once

#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include "../lua/LuaWrapper.hpp"

class ScheduleManager {
public:
  ScheduleManager(LuaWrapper &lua, World &w) : lua(lua), world(w) {}

  void resetScheduler() { scheduler.init(); }

  void scheduleMusic() {
    auto &audio = AudioSystem::instance();
    audio.music->stopMusic();
    audio.music->playLevel1Track();

    scheduler.schedule(128.0f, [&] {
      audio.music->stopMusic();
      audio.music->playBossMusic();
    });
  }

  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void updateProjectiles(float deltaTime) {
    world.projectileManager.update(deltaTime);
    world.projectileManager.draw();
  }

  void updateScheduler(float deltaTime) { scheduler.update(deltaTime); }

  Scheduler scheduler;

private:
  LuaWrapper &lua;
  World &world;
};
