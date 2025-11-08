#pragma once

#include "entities/EnemyManager.hpp"
#include "entities/Player.hpp"
#include "items/ItemsManager.hpp"
#include "projectiles/ProjectileManager.hpp"

struct World {
  EnemyManager enemyManager;
  ProjectileManager projectileManager;
  ItemManager itemManager;
  Player pwat;

  World() : enemyManager(projectileManager), pwat(projectileManager) {}
};
