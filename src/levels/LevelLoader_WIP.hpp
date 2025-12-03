// Not added to the game yet! A module to load different levels.

#pragma once

#include "ItemScheduler.hpp"
#include "ScheduleManager.hpp"
#include "SpawnScheduler.hpp"
#include <cstdint>

enum class LevelID : uint8_t {
  Tutorial,
  Level1,
  Level2,
  Level3,
  Level4,
  COUNT
};

class LevelLoader {
public:
  LevelLoader(ScheduleManager &sm, SpawnScheduler &ss, ItemScheduler &is)
      : scheduleManager(sm), spawnScheduler(ss), itemScheduler(is) {}

  LevelID currentLevel = LevelID::Tutorial;

  void load(LevelID level) {
    scheduleManager.resetScheduler();
    scheduleManager.clearAllProjectiles();
    itemScheduler.clearAllItems();
    spawnScheduler.clearAllEnemies();

    switch (level) {
    case LevelID::Tutorial:
      itemScheduler.scheduleItems("../scripts/levels/tutorialItems.lua");
      spawnScheduler.scheduleEnemies("../scripts/levels/tutorialEnemies.lua");
      break;
    case LevelID::Level1:
      itemScheduler.scheduleItems("../scripts/levels/lvl1Items.lua");
      spawnScheduler.scheduleEnemies("../scripts/levels/lvl1Enemies.lua");
    case LevelID::Level2:
      itemScheduler.scheduleItems("../scripts/levels/lvl2Items.lua");
      spawnScheduler.scheduleEnemies("../scripts/levels/lvl2Enemies.lua");
    case LevelID::Level3:
      itemScheduler.scheduleItems("../scripts/levels/lvl3Items.lua");
      spawnScheduler.scheduleEnemies("../scripts/levels/lvl3Enemies.lua");
    case LevelID::Level4:
      itemScheduler.scheduleItems("../scripts/levels/lvl4Items.lua");
      spawnScheduler.scheduleEnemies("../scripts/levels/lvl4Enemies.lua");
    default:
      break;
    }
  }

private:
  ScheduleManager &scheduleManager;
  SpawnScheduler &spawnScheduler;
  ItemScheduler &itemScheduler;
};
