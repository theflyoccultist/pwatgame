#pragma once

#include <projectiles/ProjectileFactory.hpp>

#include <array>
#include <raylib.h>
#include <span>

class ProjectileManager {
public:
  ProjectileManager() = default;

  ProjectileManager(const ProjectileManager &) = delete;
  ProjectileManager &operator=(const ProjectileManager &) = delete;

  void loadProjectileTextures();

  void spawn(const SpawnRequest &req);
  void update(float dt);
  void draw();
  void clearAll();

  std::span<Projectile *const> view();

private:
  static constexpr int BULLET_POOL = 350;
  std::array<Projectile *, BULLET_POOL> projectiles{};
  std::array<Projectile *, BULLET_POOL> tempView{};
  ProjectileFactory factory;
  float bulletTimer = 0.0f;
};
