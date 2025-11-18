#pragma once

#include "entities/EnemyManager.hpp"
#include "entities/MiniBossManager.hpp"
#include "items/ItemsManager.hpp"
#include "player/Player.hpp"
#include "projectiles/ProjectileManager.hpp"

struct World {
  EnemyManager enemyManager;
  Player pwat;
  MiniBossManager minibossManager;
  ProjectileManager projectileManager;
  ItemManager itemManager;

  World()
      : enemyManager(projectileManager), pwat(projectileManager),
        minibossManager(projectileManager) {}
};
