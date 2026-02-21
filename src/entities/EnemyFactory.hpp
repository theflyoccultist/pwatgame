#pragma once

#include <Paths/Paths.hpp>
#include <entities/EnemyPool.hpp>

class EnemyFactory {
public:
  EnemyFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();
    const fs::path assetsPath = Paths::getAssetsPath();

    Clank::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/clank_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/clank_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/clank_LOW.png").string()),
    };

    Constrainer::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/gost_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/gost_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/gost_LOW.png").string()),
    };

    Duo::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/duo_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/duo_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/duo_LOW.png").string()),
    };

    Fractal::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/fractal_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/fractal_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/fractal_LOW.png").string()),
    };

    Godsip::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/godsip_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/godsip_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/godsip_LOW.png").string()),
    };

    Miku::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/miku_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/miku_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/miku_LOW.png").string()),
    };

    Monitor::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/monitor_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/monitor_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/monitor_LOW.png").string()),
    };

    Sniper::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/sniper_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/sniper_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/sniper_LOW.png").string()),
    };

    Swarmer::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/swarmer_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/swarmer_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/swarmer_LOW.png").string()),
    };

    ThreadEmitter::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/gost_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/gost_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/gost_LOW.png").string()),
    };

    Zomb::sharedTextures = {
        &assets.loadTexture((assetsPath / "enemies/zomb_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "enemies/zomb_MED.png").string()),
        &assets.loadTexture((assetsPath / "enemies/zomb_LOW.png").string()),
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

    case EnemyType::ZOMB:
      return EnemyPool::getFreeEnemy<Zomb>(pos, spec);

    default:
      std::cerr << "EnemyFactory.hpp: Enemy *create: Unknown Enemy Type!\n";
      return nullptr;
    }
  }
};
