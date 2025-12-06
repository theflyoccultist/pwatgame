// Not added to the game yet! A module to load different levels.

#pragma once

#include "../entities/EnemyDatabase.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "ItemScheduler.hpp"
#include "ScheduleManager.hpp"
#include "SpawnScheduler.hpp"
#include <cstdint>
#include <iostream>

enum class LevelID : uint8_t { Level1, Level2, Level3, Level4, COUNT };

class LevelLoader {
public:
  LevelLoader(WeaponDataBase &wd, EnemyDatabase &ed, ScheduleManager &sm,
              SpawnScheduler &ss, ItemScheduler &is)
      : weaponDatabase(wd), enemyDatabase(ed), scheduleManager(sm),
        spawnScheduler(ss), itemScheduler(is) {}

  LevelID currentLevel = LevelID::Level1;

  void load(LevelID level) {
    scheduleManager.resetScheduler();
    scheduleManager.clearAllProjectiles();
    itemScheduler.clearAllItems();
    spawnScheduler.clearAllEnemies();

    switch (level) {
    case LevelID::Level1:
      weaponDatabase.loadFromLua("../scripts/level1/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level1/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level1/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level1/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level1/MinibossSchedule.lua");

    case LevelID::Level2:
      weaponDatabase.loadFromLua("../scripts/level2/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level2/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level2/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level2/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level2/MinibossSchedule.lua");

    case LevelID::Level3:
      weaponDatabase.loadFromLua("../scripts/level3/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level3/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level3/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level3/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level3/MinibossSchedule.lua");

    case LevelID::Level4:
      weaponDatabase.loadFromLua("../scripts/level4/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level4/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level4/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level4/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level4/MinibossSchedule.lua");

    default:
      std::cerr << "Level Loader: Unknown Game level\n";
      break;
    }
  }

  void updateLoader(float deltaTime, const PlayerState &pwatState) {
    scheduleManager.updateScheduler(deltaTime);
    scheduleManager.updateProjectiles(deltaTime);
    itemScheduler.updateItems(pwatState);
    spawnScheduler.updateEnemies(deltaTime, pwatState);
  }

private:
  WeaponDataBase &weaponDatabase;
  EnemyDatabase &enemyDatabase;
  ScheduleManager &scheduleManager;
  SpawnScheduler &spawnScheduler;
  ItemScheduler &itemScheduler;
};
