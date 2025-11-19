#include "ProjectileManager.hpp"

void ProjectileManager::spawn(Faction f, ProjectileType type,
                              const Vector2 &startPos, const Vector2 &dir) {
  Projectile *p = factory.createProjectile(f, type, startPos, dir);
  if (!p)
    return;

  for (auto &slot : projectiles) {
    if (slot == nullptr) {
      slot = p;
      return;
    }
  }
}

void ProjectileManager::update(float dt) {
  for (auto *p : projectiles)
    if (p && p->isActive())
      p->update(dt);

  for (auto &p : projectiles) {
    if (p && p->lifetime() <= 0.0f) {
      p->deactivate();
      p = nullptr;
    }
  }
}

void ProjectileManager::draw() {
  for (auto *p : projectiles) {
    if (p && p->isActive())
      p->draw();
  }
}

std::span<Projectile *const> ProjectileManager::view() {
  size_t count = 0;

  for (auto *p : projectiles)
    if (p && p->isActive())
      tempView[count++] = p;

  return {tempView.data(), count};
}

void ProjectileManager::clearAll() {
  for (auto *&p : projectiles) {
    if (p) {
      p->deactivate();
      p = nullptr;
    }
  }
}
