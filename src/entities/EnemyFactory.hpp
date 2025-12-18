#pragma once

#include "Enemy.hpp"
#include "EnemyPool.hpp"
#include "EnemySpec.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

class EnemyFactory {
public:
  EnemyFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();

    Godsip::sharedTextures = {
        &assets.loadTexture("../assets/enemies/godsip_HIGH.png"),
        &assets.loadTexture("../assets/enemies/godsip_MED.png"),
        &assets.loadTexture("../assets/enemies/godsip_LOW.png"),
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

    Zomb::sharedTextures = {
        &assets.loadTexture("../assets/enemies/zomb_HIGH.png"),
        &assets.loadTexture("../assets/enemies/zomb_MED.png"),
        &assets.loadTexture("../assets/enemies/zomb_LOW.png"),
    };
  }

  Enemy *create(EnemyType type, Vector2 pos, const EnemySpec &spec) {
    switch (type) {
    case EnemyType::GODSIP:
      return EnemyPool::getFreeEnemy<Godsip>(pos, spec);

    case EnemyType::MONITOR:
      return EnemyPool::getFreeEnemy<Monitor>(pos, spec);

    case EnemyType::SNIPER:
      return EnemyPool::getFreeEnemy<Sniper>(pos, spec);

    case EnemyType::SWARMER:
      return EnemyPool::getFreeEnemy<Swarmer>(pos, spec);

    case EnemyType::ZOMB:
      return EnemyPool::getFreeEnemy<Zomb>(pos, spec);

    default:
      std::cerr << "Unknown Enemy type!\n";
      return nullptr;
    }
  }
};
