#pragma once

#include "Enemy.hpp"
#include "Sniper.hpp"
#include "Swarmer.hpp"
#include <array>
#include <memory>

#include <iostream>
#include <raylib.h>
#include <unordered_map>

class EnemyFactory {
public:
  EnemyFactory() = default;
  int enemySize = 70;

  void loadAssets() {
    auto &assets = AssetSystem::instance();
    enemyTextures[EnemyType::SWARMER] = {
        &assets.loadTexture("../assets/enemies/swarmer_HIGH.png", enemySize,
                            enemySize),
        &assets.loadTexture("../assets/enemies/swarmer_MED.png", enemySize,
                            enemySize),
        &assets.loadTexture("../assets/enemies/swarmer_LOW.png", enemySize,
                            enemySize)};
    enemyTextures[EnemyType::SNIPER] = {
        &assets.loadTexture("../assets/enemies/sniper_HIGH.png", enemySize,
                            enemySize),
        &assets.loadTexture("../assets/enemies/sniper_MED.png", enemySize,
                            enemySize),
        &assets.loadTexture("../assets/enemies/sniper_LOW.png", enemySize,
                            enemySize)};
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
    default:
      return nullptr;
    }
  }

private:
  std::unordered_map<EnemyType, std::array<Texture2D *, 3>> enemyTextures;
};
