#include "../sound/AudioSystem.hpp"
#include "Projectile.hpp"
#include "StraightProjectile.hpp"
#include <memory>
#include <raylib.h>
#include <stdexcept>

class ProjectileFactory {
public:
  std::unique_ptr<Projectile> createProjectile(ProjectileType type,
                                               Vector2 startPos, Vector2 dir) {
    switch (type) {
    case ProjectileType::STRAIGHT:
      AudioSystem::instance().gunshotSounds();
      return std::make_unique<StraightProjectile>(startPos, dir);
    default:
      throw std::runtime_error("Unknown projectile type");
    }

    return nullptr;
  }
};
