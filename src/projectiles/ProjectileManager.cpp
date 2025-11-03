#include "ProjectileManager.hpp"
#include <algorithm>

void ProjectileManager::spawn(ProjectileType type, const Vector2 &startPos,
                              const Vector2 &dir) {
  projectiles.push_back(factory.createProjectile(type, startPos, dir));
}

void ProjectileManager::update(float dt) {
  for (auto &p : projectiles)
    p->update(dt);

  projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
                                   [](const std::unique_ptr<Projectile> &p) {
                                     return p->lifetime <= 0.0f;
                                   }),
                    projectiles.end());
}

void ProjectileManager::draw() {
  for (auto &p : projectiles)
    p->draw();
}

std::vector<Vector2> ProjectileManager::getProjectilePositions() const {
  std::vector<Vector2> positions;
  positions.reserve(projectiles.size());

  for (auto &p : projectiles)
    positions.push_back(p->position);

  return positions;
}

void ProjectileManager::clearAll() { projectiles.clear(); }
