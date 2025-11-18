#pragma once

#include "MiniBoss.hpp"
#include "MiniBoss_Windows.hpp"
#include <array>
#include <iostream>
#include <memory>
#include <raylib.h>
#include <string>
#include <unordered_map>
#include <vector>

class MiniBossFactory {
public:
  MiniBossFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();

    bossTextures[BossType::WINDOWS] = {
        &assets.loadTexture("../assets/bosses/win_HIGH.png", 200, 200),
        &assets.loadTexture("../assets/bosses/win_MED.png", 200, 200),
        &assets.loadTexture("../assets/bosses/win_LOW.png", 200, 200),
    };

    bossTextures[BossType::LISP] = {
        &assets.loadTexture("../assets/bosses/lisp_HIGH.png", 200, 200),
        &assets.loadTexture("../assets/bosses/lisp_MED.png", 200, 200),
        &assets.loadTexture("../assets/bosses/lisp_LOW.png", 200, 200),
    };

    extraAssets = {&assets.loadSprite("../assets/bosses/explosion.png")};
  }

  std::unique_ptr<MiniBoss> create(BossType type, Vector2 pos) {
    auto it = bossTextures.find(type);
    if (it == bossTextures.end()) {
      std::cerr << "MiniBossFactory::create: No textures for type\n";
      return nullptr;
    }

    const auto textures = it->second;
    switch (type) {
    case BossType::WINDOWS:
      return std::make_unique<Windows>(pos, textures);
    default:
      return nullptr;
    }
  }

  void explodeAnim() {
    AudioSystem::instance().sfx->enemyKilled();
    AssetSystem::instance().drawSprite(*extraAssets[0], {320, 320}, 19);
  }

private:
  std::unordered_map<BossType, std::array<Texture2D *, 3>> bossTextures;
  std::vector<Texture2D *> extraAssets;
};
