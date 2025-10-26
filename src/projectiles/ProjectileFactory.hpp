#include "../sound/AudioSystem.hpp"
#include "Projectile.hpp"
#include "Straight.hpp"
#include <memory>
#include <raylib.h>

class ProjectileFactory {
public:
  std::unique_ptr<Projectile> createProjectile(ProjectileType type,
                                               Vector2 startPos, Vector2 dir) {
    switch (type) {
    case ProjectileType::STRAIGHT:
      AudioSystem::instance().defaultGun();
      return std::make_unique<Straight>(startPos, dir);
    default:
      return nullptr;
    }
  }
};
