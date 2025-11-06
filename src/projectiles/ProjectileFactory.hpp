#include "../entities/Faction.hpp"
#include "../sound/AudioSystem.hpp"
#include "LongRange.hpp"
#include "Projectile.hpp"
#include "Straight.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>

class ProjectileFactory {
public:
  std::unique_ptr<Projectile> createProjectile(Faction f, ProjectileType type,
                                               Vector2 startPos, Vector2 dir) {
    switch (type) {
    case ProjectileType::STRAIGHT:
      AudioSystem::instance().defaultGun();
      return std::make_unique<Straight>(f, startPos, dir);
    case ProjectileType::LONGRANGE:
      return std::make_unique<LongRange>(f, startPos, dir);
    default:
      std::cerr << "Unknown projectile type!\n";
      return nullptr;
    }
  }
};
