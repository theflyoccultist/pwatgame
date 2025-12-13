#pragma once

#include "../entities/Faction.hpp"
#include "../sound/AudioSystem.hpp"
#include "Projectile.hpp"
#include "ProjectilePool.hpp"
#include "WeaponSpec.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>

class ProjectileFactory {
public:
  Projectile *createProjectile(Faction f, ProjectileType type, Vector2 startPos,
                               Vector2 dir, WeaponSpec spec) {
    auto &audio = AudioSystem::instance();

    switch (type) {
    case ProjectileType::STRAIGHT:
      audio.sfx->defaultGun();
      return ProjectilePool::getFreeProjectile<Straight>(f, startPos, dir,
                                                         spec);

    case ProjectileType::LONGRANGE:
      return ProjectilePool::getFreeProjectile<LongRange>(f, startPos, dir,
                                                          spec);

    case ProjectileType::SLOWCANNON:
      return ProjectilePool::getFreeProjectile<SlowCannon>(f, startPos, dir,
                                                           spec);

    case ProjectileType::ROCKET:
      audio.sfx->rocketGun();
      return ProjectilePool::getFreeProjectile<Rocket>(f, startPos, dir, spec);

    case ProjectileType::UZI:
      audio.sfx->uziGun();
      return ProjectilePool::getFreeProjectile<Uzi>(f, startPos, dir, spec);

    case ProjectileType::HELLFIRE:
      audio.sfx->hellfire();
      return ProjectilePool::getFreeProjectile<Hellfire>(f, startPos, dir,
                                                         spec);

    case ProjectileType::GRENADE:
      audio.sfx->grenade();
      return ProjectilePool::getFreeProjectile<Grenade>(f, startPos, dir, spec);

    default:
      std::cerr << "Unknown projectile type!\n";
      return nullptr;
    }
  }
};
