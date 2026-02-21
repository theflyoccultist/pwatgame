#pragma once

#include <Paths/Paths.hpp>
#include <projectiles/Projectile.hpp>
#include <projectiles/ProjectilePool.hpp>
#include <sound/AudioSystem.hpp>
#include <texture/AssetSystem.hpp>

#include <iostream>
#include <memory>

class ProjectileFactory {
public:
  ProjectileFactory() = default;

  void loadAssets() {
    const fs::path assetsPath = Paths::getAssetsPath();
    auto &asset = AssetSystem::instance();

    Elixir::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_elixir.png").string());

    Executable::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_exe.png").string());

    Grenade::projTexture = &asset.loadTexture(
        (assetsPath / "bullets/bullet_grenade.png").string());

    Hellfire::projTexture = &asset.loadTexture(
        (assetsPath / "bullets/bullet_hellfire.png").string());

    Internet::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_ie.png").string());

    Lambda::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_lambda.png").string());

    LongRange::projTexture = &asset.loadTexture(
        (assetsPath / "bullets/bullet_longrange.png").string());

    Paren::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_paren.png").string());

    Recon::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_recon.png").string());

    Rocket::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_rocket.png").string());

    SlowCannon::projTexture = &asset.loadTexture(
        (assetsPath / "bullets/bullet_slowcannon.png").string());

    Straight::projTexture = &asset.loadTexture(
        (assetsPath / "bullets/bullet_straight.png").string());

    Update::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_update.png").string());

    Uzi::projTexture =
        &asset.loadTexture((assetsPath / "bullets/bullet_uzi.png").string());

    Warning::projTexture = &asset.loadTexture(
        (assetsPath / "bullets/bullet_warning.png").string());
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
