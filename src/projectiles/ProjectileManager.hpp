#pragma once

#include "ProjectileFactory.hpp"
#include <array>
#include <raylib.h>
#include <span>

class ProjectileManager {
public:
  void spawn(Faction f, ProjectileType type, const Vector2 &startPos,
             const Vector2 &dir, const WeaponSpec &spec);
  void update(float dt);
  void draw();
  void clearAll();

  std::span<Projectile *const> view();

private:
  static constexpr int BULLET_POOL = 350;
  std::array<Projectile *, BULLET_POOL> projectiles{};
  std::array<Projectile *, BULLET_POOL> tempView{};
  ProjectileFactory factory;
};
