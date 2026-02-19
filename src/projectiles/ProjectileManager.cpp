#include <projectiles/ProjectileManager.hpp>

void ProjectileManager::loadProjectileTextures() { factory.loadAssets(); }

void ProjectileManager::spawn(const SpawnRequest &req) {
  Projectile *p = factory.createProjectile(req);
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
    if (p && p->stats.lifetime <= 0.0f) {
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
