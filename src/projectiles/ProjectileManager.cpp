#include "ProjectileManager.hpp"

void ProjectileManager::spawn(Faction f, ProjectileType type,
                              const Vector2 &startPos, const Vector2 &dir) {
  projectiles.push_back(factory.createProjectile(f, type, startPos, dir));
}

void ProjectileManager::update(float dt) {
  for (auto &p : projectiles)
    p->update(dt);

  std::erase_if(projectiles, [](auto &p) { return p->lifetime <= 0.0f; });
}

void ProjectileManager::draw() {
  for (auto &p : projectiles)
    p->draw();
}

std::span<Projectile *const> ProjectileManager::view() {
  tempView.clear();
  tempView.reserve(projectiles.size());

  for (auto &p : projectiles)
    tempView.push_back(p.get());

  return tempView;
}

void ProjectileManager::clearAll() { projectiles.clear(); }
