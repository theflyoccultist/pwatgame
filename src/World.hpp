#pragma once

#include "entities/EnemyManager.hpp"
#include "entities/MiniBossManager.hpp"
#include "items/ItemsManager.hpp"
#include "player/Player.hpp"
#include "projectiles/ProjectileManager.hpp"

struct World {
  ProjectileManager projectileManager;
  EnemyManager enemyManager;
  Player pwat;
  MiniBossManager minibossManager;
  ItemManager itemManager;

  World()
      : enemyManager(projectileManager), pwat(projectileManager),
        minibossManager(projectileManager) {
    itemManager.loadItemTextures();
  }
};
