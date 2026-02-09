#pragma once

#include "Enemy.hpp"
#include "EnemyPool.hpp"
#include "EnemySpec.hpp"
#include "EnemyType.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

class EnemyFactory {
public:
  EnemyFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();

    Clank::sharedTextures = {
        &assets.loadTexture("../assets/enemies/clank_HIGH.png"),
        &assets.loadTexture("../assets/enemies/clank_MED.png"),
        &assets.loadTexture("../assets/enemies/clank_LOW.png"),
    };

    Constrainer::sharedTextures = {
        &assets.loadTexture("../assets/enemies/gost_HIGH.png"),
        &assets.loadTexture("../assets/enemies/gost_MED.png"),
        &assets.loadTexture("../assets/enemies/gost_LOW.png"),
    };

    Duo::sharedTextures = {
        &assets.loadTexture("../assets/enemies/duo_HIGH.png"),
        &assets.loadTexture("../assets/enemies/duo_MED.png"),
        &assets.loadTexture("../assets/enemies/duo_LOW.png"),
    };

    Fractal::sharedTextures = {
        &assets.loadTexture("../assets/enemies/fractal_HIGH.png"),
        &assets.loadTexture("../assets/enemies/fractal_MED.png"),
        &assets.loadTexture("../assets/enemies/fractal_LOW.png"),
    };

    Godsip::sharedTextures = {
        &assets.loadTexture("../assets/enemies/godsip_HIGH.png"),
        &assets.loadTexture("../assets/enemies/godsip_MED.png"),
        &assets.loadTexture("../assets/enemies/godsip_LOW.png"),
    };

    Miku::sharedTextures = {
        &assets.loadTexture("../assets/enemies/miku_HIGH.png"),
        &assets.loadTexture("../assets/enemies/miku_MED.png"),
        &assets.loadTexture("../assets/enemies/miku_LOW.png"),
    };

    Monitor::sharedTextures = {
        &assets.loadTexture("../assets/enemies/monitor_HIGH.png"),
        &assets.loadTexture("../assets/enemies/monitor_MED.png"),
        &assets.loadTexture("../assets/enemies/monitor_LOW.png"),
    };

    Sniper::sharedTextures = {
        &assets.loadTexture("../assets/enemies/sniper_HIGH.png"),
        &assets.loadTexture("../assets/enemies/sniper_MED.png"),
        &assets.loadTexture("../assets/enemies/sniper_LOW.png"),
    };

    Swarmer::sharedTextures = {
        &assets.loadTexture("../assets/enemies/swarmer_HIGH.png"),
        &assets.loadTexture("../assets/enemies/swarmer_MED.png"),
        &assets.loadTexture("../assets/enemies/swarmer_LOW.png"),
    };

    ThreadEmitter::sharedTextures = {
        &assets.loadTexture("../assets/enemies/gost_HIGH.png"),
        &assets.loadTexture("../assets/enemies/gost_MED.png"),
        &assets.loadTexture("../assets/enemies/gost_LOW.png"),
    };

    Walled::sharedTextures = {
        &assets.loadTexture("../assets/enemies/wall_warning.png"),
        &assets.loadTexture("../assets/enemies/wall_appear.png"),
        &assets.loadTexture("../assets/enemies/wall_appear.png"),
    };

    WalledMove::sharedTextures = {
        &assets.loadTexture("../assets/enemies/wall_warning.png"),
        &assets.loadTexture("../assets/enemies/wall_moving.png"),
        &assets.loadTexture("../assets/enemies/wall_moving.png"),
    };

    Zomb::sharedTextures = {
        &assets.loadTexture("../assets/enemies/zomb_HIGH.png"),
        &assets.loadTexture("../assets/enemies/zomb_MED.png"),
        &assets.loadTexture("../assets/enemies/zomb_LOW.png"),
    };
  }

  Enemy *create(EnemyType type, Vector2 pos, const EnemySpec &spec) {
    switch (type) {
    case EnemyType::CLANK:
      return EnemyPool::getFreeEnemy<Clank>(pos, spec);

    case EnemyType::CONSTRAINER:
      return EnemyPool::getFreeEnemy<Constrainer>(pos, spec);

    case EnemyType::DUO:
      return EnemyPool::getFreeEnemy<Duo>(pos, spec);

    case EnemyType::FRACTAL:
      return EnemyPool::getFreeEnemy<Fractal>(pos, spec);

    case EnemyType::GODSIP:
      return EnemyPool::getFreeEnemy<Godsip>(pos, spec);

    case EnemyType::MIKU:
      return EnemyPool::getFreeEnemy<Miku>(pos, spec);

    case EnemyType::MONITOR:
      return EnemyPool::getFreeEnemy<Monitor>(pos, spec);

    case EnemyType::SNIPER:
      return EnemyPool::getFreeEnemy<Sniper>(pos, spec);

    case EnemyType::SWARMER:
      return EnemyPool::getFreeEnemy<Swarmer>(pos, spec);

    case EnemyType::THREADEMITTER:
      return EnemyPool::getFreeEnemy<ThreadEmitter>(pos, spec);

    case EnemyType::WALLED:
      return EnemyPool::getFreeEnemy<Walled>(pos, spec);

    case EnemyType::WALLEDMOVE:
      return EnemyPool::getFreeEnemy<WalledMove>(pos, spec);

    case EnemyType::ZOMB:
      return EnemyPool::getFreeEnemy<Zomb>(pos, spec);

    default:
      std::cerr << "EnemyFactory.hpp: Enemy *create: Unknown Enemy Type!\n";
      return nullptr;
    }
  }
};
