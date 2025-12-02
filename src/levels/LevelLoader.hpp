#pragma once

#include "ItemScheduler.hpp"
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
  LevelLoader(SpawnScheduler &ss, ItemScheduler &is)
      : spawnScheduler(ss), itemScheduler(is) {}

  LevelID currentLevel = LevelID::Tutorial;

  void load(LevelID level) {
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
    default:
      break;
    }
  }

private:
  SpawnScheduler &spawnScheduler;
  ItemScheduler &itemScheduler;
};
