#pragma once

#include "Enemy.hpp"
#include "EnemyPool.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

class EnemyFactory {
public:
  EnemyFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();

    Godsip::sharedTextures = {
        &assets.loadTexture("../assets/enemies/godsip_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/godsip_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/godsip_LOW.png", 70, 70),
    };

    Monitor::sharedTextures = {
        &assets.loadTexture("../assets/enemies/monitor_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/monitor_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/monitor_LOW.png", 70, 70),
    };

    Sniper::sharedTextures = {
        &assets.loadTexture("../assets/enemies/sniper_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/sniper_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/sniper_LOW.png", 70, 70),
    };

    Swarmer::sharedTextures = {
        &assets.loadTexture("../assets/enemies/swarmer_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/swarmer_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/swarmer_LOW.png", 70, 70),
    };

    Zomb::sharedTextures = {
        &assets.loadTexture("../assets/enemies/zomb_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/zomb_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/zomb_LOW.png", 70, 70),
    };
  }

  Enemy *create(EnemyType type, Vector2 pos) {
    switch (type) {
    case EnemyType::GODSIP:
      return EnemyPool::getFreeEnemy<Godsip>(pos);

    case EnemyType::MONITOR:
      return EnemyPool::getFreeEnemy<Monitor>(pos);

    case EnemyType::SNIPER:
      return EnemyPool::getFreeEnemy<Sniper>(pos);

    case EnemyType::SWARMER:
      return EnemyPool::getFreeEnemy<Swarmer>(pos);

    case EnemyType::ZOMB:
      return EnemyPool::getFreeEnemy<Zomb>(pos);

    default:
      std::cerr << "Unknown Enemy type!\n";
      return nullptr;
    }
  }
};
