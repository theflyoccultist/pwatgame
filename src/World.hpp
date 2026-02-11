#pragma once

#include "entities/EnemyManager.hpp"
#include "entities/MiniBossManager.hpp"
#include "entities/WallManager.hpp"
#include "items/ItemsManager.hpp"
#include "player/Player.hpp"
#include "projectiles/ProjectileManager.hpp"

struct World {
  ProjectileManager projectileManager;
  EnemyManager enemyManager;
  Player pwat;
  MiniBossManager minibossManager;
  ItemManager itemManager;
  WallManager wallManager;

  World()
      : enemyManager(projectileManager), pwat(projectileManager),
        minibossManager(projectileManager) {}
};
