#pragma once

#include <entities/EnemyDatabase.hpp>
#include <entities/MiniBossDatabase.hpp>
#include <levels/ItemScheduler.hpp>
#include <levels/LevelID.hpp>
#include <levels/ProjectileScheduler.hpp>
#include <levels/SpawnScheduler.hpp>
#include <projectiles/WeaponDatabase.hpp>

#include <iostream>

class LevelLoader {
public:
  LevelLoader(WeaponDataBase &wd, EnemyDatabase &ed, MiniBossDatabase &md,
              ScheduleManager &sm, SpawnScheduler &ss, ItemScheduler &is,
              ProjectileScheduler &ps)
      : weaponDatabase(wd), enemyDatabase(ed), minibossDatabase(md),
        scheduleManager(sm), spawnScheduler(ss), itemScheduler(is),
        projectileScheduler(ps) {}

  LevelLoader &operator=(const LevelLoader &) = delete;
  LevelLoader &operator=(const LevelLoader &&) = delete;

  void initDatabase() {
    weaponDatabase.loadFromLua("../scripts/common/DefaultWeaponData.lua");
  }

  void loadEntityTextures() {
    spawnScheduler.loadEnemyTextures();
    spawnScheduler.loadWallTextures();
    spawnScheduler.loadMiniBossTextures();
    itemScheduler.loadItemTextures();
    projectileScheduler.loadProjectileTextures();
  }

  void load(LevelID level) {
    scheduleManager.resetScheduler();
    projectileScheduler.clearAllProjectiles();
    itemScheduler.clearAllItems();
    spawnScheduler.clearAllEnemies();
    spawnScheduler.clearAllWalls();

    minibossDatabase.loadFromLua("../scripts/common/MinibossData.lua");

    switch (level) {
    case LevelID::Level1:
      weaponDatabase.loadFromLua("../scripts/level1/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level1/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level1/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level1/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level1/MinibossSchedule.lua");
      break;

    case LevelID::Level2:
      weaponDatabase.loadFromLua("../scripts/level2/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level2/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level2/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level2/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level2/MinibossSchedule.lua");
      break;

    case LevelID::Level3:
      weaponDatabase.loadFromLua("../scripts/level3/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level3/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level3/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level3/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level3/MinibossSchedule.lua");
      break;

    case LevelID::Level4:
      weaponDatabase.loadFromLua("../scripts/level4/WeaponData.lua");
      enemyDatabase.loadFromLua("../scripts/level4/EnemyData.lua");
      spawnScheduler.scheduleEnemies("../scripts/level4/EnemySchedule.lua");
      itemScheduler.scheduleItems("../scripts/level4/ItemSchedule.lua");
      spawnScheduler.scheduleMiniBoss("../scripts/level4/MinibossSchedule.lua");
      spawnScheduler.scheduleWalls("../scripts/level4/WallSchedule.lua");
      break;

    default:
      std::cerr << "Level Loader: Unknown Game level\n";
      break;
    }
  }

private:
  WeaponDataBase &weaponDatabase;
  EnemyDatabase &enemyDatabase;
  MiniBossDatabase &minibossDatabase;
  ScheduleManager &scheduleManager;
  SpawnScheduler &spawnScheduler;
  ItemScheduler &itemScheduler;
  ProjectileScheduler &projectileScheduler;
};
