#include "ProjectileManager.hpp"
#include "WeaponSpec.hpp"

void ProjectileManager::loadProjectileTextures() { factory.loadAssets(); }

void ProjectileManager::spawn(Faction f, ProjectileType type,
                              const Vector2 &startPos, const Vector2 &dir,
                              const WeaponSpec &spec) {
  Projectile *p = factory.createProjectile(f, type, startPos, dir, spec);
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
  bulletTimer += dt;
  float bulletCooldown = std::fmodf(bulletTimer, 4.0f);

  for (auto *p : projectiles)
    if (p && p->isActive())
      p->update(dt, bulletCooldown);

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
