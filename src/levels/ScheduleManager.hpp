#pragma once

#include "../World.hpp"
#include "../levels/Scheduler.hpp"
#include "../lua/LuaWrapper.hpp"
#include <expected>

class ScheduleManager {
public:
  ScheduleManager(LuaWrapper &lua, World &w) : lua(lua), world(w) {}

  void resetScheduler() { scheduler.init(); }

  void loadScript(const char *filename) {
    lua.runFile(filename).or_else([](LuaError e) {
      std::cerr << e << "\n";
      return std::expected<void, LuaError>();
    });
  }

  void scheduleMusic() {
    auto &audio = AudioSystem::instance();
    audio.music->stopMusic();
    audio.music->playLevelTrack();

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
