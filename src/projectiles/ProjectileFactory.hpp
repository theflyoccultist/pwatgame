#pragma once

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
        &asset.loadTexture("../assets/bullets/bullet_grenade.png");

    Hellfire::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_hellfire.png");

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

    Warning::projTexture =
        &asset.loadTexture("../assets/bullets/bullet_warning.png");
  }

  Projectile *createProjectile(const SpawnRequest &req) {
    auto &audio = AudioSystem::instance();

    switch (req.type) {
    case ProjectileType::ELIXIR:
      return ProjectilePool::getFreeProjectile<Elixir>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::EXECUTABLE:
      return ProjectilePool::getFreeProjectile<Executable>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::GRENADE:
      audio.sfx->grenade();
      return ProjectilePool::getFreeProjectile<Grenade>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::HELLFIRE:
      audio.sfx->hellfire();
      return ProjectilePool::getFreeProjectile<Hellfire>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::INTERNET:
      return ProjectilePool::getFreeProjectile<Internet>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::LAMBDA:
      return ProjectilePool::getFreeProjectile<Lambda>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::LONGRANGE:
      return ProjectilePool::getFreeProjectile<LongRange>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::PAREN:
      return ProjectilePool::getFreeProjectile<Paren>(req.faction, req.startPos,
                                                      req.direction, req.spec);

    case ProjectileType::RECON:
      return ProjectilePool::getFreeProjectile<Recon>(req.faction, req.startPos,
                                                      req.direction, req.spec);

    case ProjectileType::ROCKET:
      audio.sfx->rocketGun();
      return ProjectilePool::getFreeProjectile<Rocket>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::SLOWCANNON:
      return ProjectilePool::getFreeProjectile<SlowCannon>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::STRAIGHT:
      audio.sfx->defaultGun();
      return ProjectilePool::getFreeProjectile<Straight>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::UPDATE:
      return ProjectilePool::getFreeProjectile<Update>(
          req.faction, req.startPos, req.direction, req.spec);

    case ProjectileType::UZI:
      audio.sfx->uziGun();
      return ProjectilePool::getFreeProjectile<Uzi>(req.faction, req.startPos,
                                                    req.direction, req.spec);

    case ProjectileType::WARNING:
      return ProjectilePool::getFreeProjectile<Warning>(
          req.faction, req.startPos, req.direction, req.spec);

    default:
      std::cerr << "Projectile Factory: Unknown projectile type!\n";
      return nullptr;
    }
  }
};
