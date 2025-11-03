#pragma once

#include "ProjectileFactory.hpp"
#include <memory>
#include <raylib.h>
#include <vector>

class ProjectileManager {
public:
  static ProjectileManager &instance() {
    static ProjectileManager instance;
    return instance;
  }

  void spawn(ProjectileType type, const Vector2 &startPos, const Vector2 &dir);
  void update(float dt);
  void draw();
  void clearAll();

  std::vector<Vector2> getProjectilePositions() const;

private:
  std::vector<std::unique_ptr<Projectile>> projectiles;
  ProjectileFactory factory;
};
