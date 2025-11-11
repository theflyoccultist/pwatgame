#include "../entities/Faction.hpp"
#include "../sound/AudioSystem.hpp"
#include "Proj_LongRange.hpp"
#include "Proj_SlowCannon.hpp"
#include "Proj_Straight.hpp"
#include "Proj_rocket.hpp"
#include "Projectile.hpp"
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
    case ProjectileType::SLOWCANNON:
      return std::make_unique<SlowCannon>(f, startPos, dir);
    case ProjectileType::ROCKET:
      AudioSystem::instance().rocketGun();
      return std::make_unique<Rocket>(f, startPos, dir);
    default:
      std::cerr << "Unknown projectile type!\n";
      return nullptr;
    }
  }
};
