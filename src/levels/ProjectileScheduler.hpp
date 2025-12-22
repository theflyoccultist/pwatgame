#pragma once

#include "../World.hpp"

class ProjectileScheduler {
public:
  ProjectileScheduler(World &w) : world(w) {}

  void loadProjectileTextures() {
    world.projectileManager.loadProjectileTextures();
  }

  void clearAllProjectiles() { world.projectileManager.clearAll(); }

  void updateProjectiles(float deltaTime) {
    world.projectileManager.update(deltaTime);
    world.projectileManager.draw();
  }

private:
  World &world;
};
