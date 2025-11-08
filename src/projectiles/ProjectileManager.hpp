#pragma once

#include "ProjectileFactory.hpp"
#include <memory>
#include <raylib.h>
#include <span>
#include <vector>

class ProjectileManager {
public:
  void spawn(Faction f, ProjectileType type, const Vector2 &startPos,
             const Vector2 &dir);
  void update(float dt);
  void draw();
  void clearAll();

  std::span<Projectile *const> view();

private:
  std::vector<std::unique_ptr<Projectile>> projectiles;
  std::vector<Projectile *> tempView;
  ProjectileFactory factory;
};
