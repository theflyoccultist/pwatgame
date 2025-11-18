#pragma once

#include "Enemy.hpp"
#include "Enemy_Godsip.hpp"
#include "Enemy_Monitor.hpp"
#include "Enemy_Sniper.hpp"
#include "Enemy_Swarmer.hpp"
#include "Enemy_Zomb.hpp"
#include <array>
#include <iostream>
#include <raylib.h>
#include <unordered_map>

class EnemyFactory {
public:
  EnemyFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();

    enemyTextures[EnemyType::SWARMER] = {
        &assets.loadTexture("../assets/enemies/swarmer_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/swarmer_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/swarmer_LOW.png", 70, 70),
    };

    enemyTextures[EnemyType::SNIPER] = {
        &assets.loadTexture("../assets/enemies/sniper_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/sniper_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/sniper_LOW.png", 70, 70),
    };

    enemyTextures[EnemyType::GODSIP] = {
        &assets.loadTexture("../assets/enemies/godsip_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/godsip_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/godsip_LOW.png", 70, 70),
    };

    enemyTextures[EnemyType::ZOMB] = {
        &assets.loadTexture("../assets/enemies/zomb_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/zomb_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/zomb_LOW.png", 70, 70),
    };

    enemyTextures[EnemyType::MONITOR] = {
        &assets.loadTexture("../assets/enemies/monitor_HIGH.png", 70, 70),
        &assets.loadTexture("../assets/enemies/monitor_MED.png", 70, 70),
        &assets.loadTexture("../assets/enemies/monitor_LOW.png", 70, 70),
    };
  }

  std::unique_ptr<Enemy> create(EnemyType type, Vector2 pos) {
    auto it = enemyTextures.find(type);
    if (it == enemyTextures.end()) {
      std::cerr << "EnemyFactory::create: No textures for type\n";
      return nullptr;
    }
    const auto textures = it->second;
    switch (type) {
    case EnemyType::SWARMER:
      return std::make_unique<Swarmer>(pos, textures);
    case EnemyType::SNIPER:
      return std::make_unique<Sniper>(pos, textures);
    case EnemyType::GODSIP:
      return std::make_unique<Godsip>(pos, textures);
    case EnemyType::ZOMB:
      return std::make_unique<Zomb>(pos, textures);
    case EnemyType::MONITOR:
      return std::make_unique<Gost>(pos, textures);
    default:
      return nullptr;
    }
  }

private:
  std::unordered_map<EnemyType, std::array<Texture2D *, 3>> enemyTextures;
};
