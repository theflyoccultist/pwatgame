#pragma once

#include "../World.hpp"
#include "../levels/ScheduleManager.hpp"
#include "LevelID.hpp"

class MusicScheduler {
public:
  MusicScheduler(World &w, ScheduleManager &sm) : world(w), sm(sm) {}

  void scheduleMusic(LevelID level) {
    auto &audio = AudioSystem::instance();
    audio.music->stopMusic();
    switch (level) {
    case LevelID::Level1:
      audio.music->playLevel1Track();
      scheduleBossMusic(128.0f);
      break;
    case LevelID::Level2:
      audio.music->playLevel2Track();
      scheduleBossMusic(174.0f);
      break;
    case LevelID::Level3:
      audio.music->playLevel3Track();
      scheduleBossMusic(160.0f);
      break;
    case LevelID::Level4:
      audio.music->playLevel4Track();
      scheduleBossMusic(143.0f);
      break;
    }
  }

private:
  void scheduleBossMusic(float bossDelay) {
    auto &audio = AudioSystem::instance();
    sm.scheduler.schedule(bossDelay, [&] {
      audio.music->stopMusic();
      audio.music->playBossMusic();
    });
  }

  World &world;
  ScheduleManager &sm;
};
