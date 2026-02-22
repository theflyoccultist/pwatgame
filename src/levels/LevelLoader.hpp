#pragma once

#include <Paths/Paths.hpp>
#include <entities/EnemyDatabase.hpp>
#include <entities/MiniBossDatabase.hpp>
#include <levels/ItemScheduler.hpp>
#include <levels/LevelID.hpp>
#include <levels/ProjectileScheduler.hpp>
#include <levels/SpawnScheduler.hpp>
#include <projectiles/WeaponDatabase.hpp>

#include <iostream>

class LevelLoader {
private:
  const fs::path scriptsPath = Paths::getScriptsPath();

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
    weaponDatabase.loadFromLua(
        (scriptsPath / "common/DefaultWeaponData.lua").string().c_str());
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

    minibossDatabase.loadFromLua(
        (scriptsPath / "common/MinibossData.lua").string().c_str());

    switch (level) {
    case LevelID::Level1:
      weaponDatabase.loadFromLua(
          (scriptsPath / "level1/WeaponData.lua").string().c_str());
      enemyDatabase.loadFromLua(
          (scriptsPath / "level1/EnemyData.lua").string().c_str());
      spawnScheduler.scheduleEnemies(
          (scriptsPath / "level1/EnemySchedule.lua").string().c_str());
      itemScheduler.scheduleItems(
          (scriptsPath / "level1/ItemSchedule.lua").string().c_str());
      spawnScheduler.scheduleMiniBoss(
          (scriptsPath / "level1/MinibossSchedule.lua").string().c_str());
      break;

    case LevelID::Level2:
      weaponDatabase.loadFromLua(
          (scriptsPath / "level2/WeaponData.lua").string().c_str());
      enemyDatabase.loadFromLua(
          (scriptsPath / "level2/EnemyData.lua").string().c_str());
      spawnScheduler.scheduleEnemies(
          (scriptsPath / "level2/EnemySchedule.lua").string().c_str());
      itemScheduler.scheduleItems(
          (scriptsPath / "level2/ItemSchedule.lua").string().c_str());
      spawnScheduler.scheduleMiniBoss(
          (scriptsPath / "level2/MinibossSchedule.lua").string().c_str());
      break;

    case LevelID::Level3:
      weaponDatabase.loadFromLua(
          (scriptsPath / "level3/WeaponData.lua").string().c_str());
      enemyDatabase.loadFromLua(
          (scriptsPath / "level3/EnemyData.lua").string().c_str());
      spawnScheduler.scheduleEnemies(
          (scriptsPath / "level3/EnemySchedule.lua").string().c_str());
      itemScheduler.scheduleItems(
          (scriptsPath / "level3/ItemSchedule.lua").string().c_str());
      spawnScheduler.scheduleMiniBoss(
          (scriptsPath / "level3/MinibossSchedule.lua").string().c_str());
      break;

    case LevelID::Level4:
      weaponDatabase.loadFromLua(
          (scriptsPath / "level4/WeaponData.lua").string().c_str());
      enemyDatabase.loadFromLua(
          (scriptsPath / "level4/EnemyData.lua").string().c_str());
      spawnScheduler.scheduleEnemies(
          (scriptsPath / "level4/EnemySchedule.lua").string().c_str());
      itemScheduler.scheduleItems(
          (scriptsPath / "level4/ItemSchedule.lua").string().c_str());
      spawnScheduler.scheduleMiniBoss(
          (scriptsPath / "level4/MinibossSchedule.lua").string().c_str());
      spawnScheduler.scheduleWalls(
          (scriptsPath / "level4/WallSchedule.lua").string().c_str());
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
