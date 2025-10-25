#include "ProjectileFactory.hpp"
#include "../sound/AudioSystem.hpp"
#include "StraightProjectile.hpp"
#include <stdexcept>

std::unique_ptr<Projectile>
ProjectileFactory::createProjectile(ProjectileType type, Vector2 startPos,
                                    Vector2 dir) {

  switch (type) {
  case ProjectileType::STRAIGHT:
    AudioSystem::instance().gunshotSounds();
    return std::make_unique<StraightProjectile>(startPos, dir);
  default:
    throw std::runtime_error("Unknown projectile type");
  }

  return nullptr;
}
