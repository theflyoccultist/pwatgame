#pragma once

#include "../entities/Faction.hpp"
#include "../sound/AudioSystem.hpp"
#include "../texture/AssetSystem.hpp"
#include "Projectile.hpp"
#include "ProjectilePool.hpp"
#include "WeaponSpec.hpp"
#include <iostream>
#include <memory>
#include <raylib.h>

class ProjectileFactory {
public:
  ProjectileFactory() = default;

  static void loadAssets() {
    auto &asset = AssetSystem::instance();

    Elixir::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_elixir.png");

    Executable::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_exe.png");

    Grenade::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_check.png");

    Hellfire::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_check.png");

    Internet::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_ie.png");

    Lambda::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_lambda.png");

    LongRange::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_longrange.png");

    Paren::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_paren.png");

    Recon::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_recon.png");

    Rocket::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_rocket.png");

    SlowCannon::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_slowcannon.png");

    Straight::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_straight.png");

    Update::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_update.png");

    Uzi::projTexture = &asset.loadTexture("../assets/bullets/bullet_uzi.png");
  }

  Projectile *createProjectile(Faction f, ProjectileType type, Vector2 startPos,
                               Vector2 dir, WeaponSpec spec) {
    auto &audio = AudioSystem::instance();

    switch (type) {
    case ProjectileType::ELIXIR:
      return ProjectilePool::getFreeProjectile<Elixir>(f, startPos, dir, spec);

    case ProjectileType::EXECUTABLE:
      return ProjectilePool::getFreeProjectile<Executable>(f, startPos, dir,
                                                           spec);

    case ProjectileType::GRENADE:
      audio.sfx->grenade();
      return ProjectilePool::getFreeProjectile<Grenade>(f, startPos, dir, spec);

    case ProjectileType::HELLFIRE:
      audio.sfx->hellfire();
      return ProjectilePool::getFreeProjectile<Hellfire>(f, startPos, dir,
                                                         spec);

    case ProjectileType::INTERNET:
      return ProjectilePool::getFreeProjectile<Internet>(f, startPos, dir,
                                                         spec);

    case ProjectileType::LAMBDA:
      return ProjectilePool::getFreeProjectile<Lambda>(f, startPos, dir, spec);

    case ProjectileType::LONGRANGE:
      return ProjectilePool::getFreeProjectile<LongRange>(f, startPos, dir,
                                                          spec);

    case ProjectileType::PAREN:
      return ProjectilePool::getFreeProjectile<Paren>(f, startPos, dir, spec);

    case ProjectileType::RECON:
      return ProjectilePool::getFreeProjectile<Recon>(f, startPos, dir, spec);

    case ProjectileType::ROCKET:
      audio.sfx->rocketGun();
      return ProjectilePool::getFreeProjectile<Rocket>(f, startPos, dir, spec);

    case ProjectileType::SLOWCANNON:
      return ProjectilePool::getFreeProjectile<SlowCannon>(f, startPos, dir,
                                                           spec);

    case ProjectileType::STRAIGHT:
      audio.sfx->defaultGun();
      return ProjectilePool::getFreeProjectile<Straight>(f, startPos, dir,
                                                         spec);

    case ProjectileType::UPDATE:
      return ProjectilePool::getFreeProjectile<Update>(f, startPos, dir, spec);

    case ProjectileType::UZI:
      audio.sfx->uziGun();
      return ProjectilePool::getFreeProjectile<Uzi>(f, startPos, dir, spec);

    default:
      std::cerr << "Projectile Factory: Unknown projectile type!\n";
      return nullptr;
    }
  }
};
