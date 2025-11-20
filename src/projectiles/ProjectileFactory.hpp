#pragma once

#include "../entities/Faction.hpp"
#include "../sound/AudioSystem.hpp"
#include "ProjectilePool.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>

class ProjectileFactory {
public:
  Projectile *createProjectile(Faction f, ProjectileType type, Vector2 startPos,
                               Vector2 dir) {
    auto &audio = AudioSystem::instance();

    switch (type) {
    case ProjectileType::STRAIGHT:
      audio.sfx->defaultGun();
      return ProjectilePool::getFreeProjectile<Straight>(f, startPos, dir);

    case ProjectileType::LONGRANGE:
      return ProjectilePool::getFreeProjectile<LongRange>(f, startPos, dir);

    case ProjectileType::SLOWCANNON:
      return ProjectilePool::getFreeProjectile<SlowCannon>(f, startPos, dir);

    case ProjectileType::ROCKET:
      audio.sfx->rocketGun();
      return ProjectilePool::getFreeProjectile<Rocket>(f, startPos, dir);

    default:
      std::cerr << "Unknown projectile type!\n";
      return nullptr;
    }
  }
};
