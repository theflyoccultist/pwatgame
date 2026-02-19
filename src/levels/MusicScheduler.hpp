#pragma once

#include <World.hpp>
#include <levels/LevelID.hpp>
#include <levels/ScheduleManager.hpp>

class MusicScheduler {
public:
  MusicScheduler(World &w, ScheduleManager &sm) : world(w), sm(sm) {}

  MusicScheduler &operator=(const MusicScheduler &) = delete;
  MusicScheduler &operator=(const MusicScheduler &&) = delete;

  void scheduleMusic(LevelID level) {
    auto &audio = AudioSystem::instance();
    audio.music->stopMusic();
    switch (level) {
    case LevelID::Level1:
      audio.music->playLevel1Track();
      break;
    case LevelID::Level2:
      audio.music->playLevel2Track();
      break;
    case LevelID::Level3:
      audio.music->playLevel3Track();
      break;
    case LevelID::Level4:
      audio.music->playLevel4Track();
      break;
    }
  }

  void scheduleBossMusic(LevelID level) {
    auto &audio = AudioSystem::instance();
    switch (level) {
    case LevelID::Level1:
      sm.scheduler.schedule(128.0f, [&] {
        audio.music->stopMusic();
        audio.music->playLevel1BossMusic();
      });
      break;
    case LevelID::Level2:
      sm.scheduler.schedule(69.0f, [&] {
        audio.music->stopMusic();
        audio.music->playLevel2BossMusic();
      });
      break;
    case LevelID::Level3:
      sm.scheduler.schedule(86.0f, [&] {
        audio.music->stopMusic();
        audio.music->playLevel3BossMusic();
      });
      break;
    case LevelID::Level4:
      sm.scheduler.schedule(116.0f, [&] {
        audio.music->stopMusic();
        audio.music->playLevel4BossMusic();
      });
      break;
    }
  }

  World &world;
  ScheduleManager &sm;
};
