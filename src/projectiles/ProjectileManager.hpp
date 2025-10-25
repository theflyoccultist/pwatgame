#pragma once
#include "Projectile.hpp"
#include "ProjectileFactory.hpp"
#include <memory>
#include <raylib.h>
#include <vector>

class ProjectileManager {
public:
  void init();
  void spawn(ProjectileType type, Vector2 startPos, Vector2 dir);
  void update(float dt);
  void draw() const;

  std::vector<Vector2> getProjectilePositions() const;

private:
  std::vector<std::unique_ptr<Projectile>> projectiles;
};
