#pragma once

#include "MiniBoss.hpp"
#include "MiniBossPool.hpp"
#include "MiniBossType.hpp"
#include <array>
#include <iostream>
#include <raylib.h>
#include <string>

class MiniBossFactory {
public:
  MiniBossFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();

    Windows::sharedTextures = {
        &assets.loadTexture("../assets/bosses/win_HIGH.png", 200, 200),
        &assets.loadTexture("../assets/bosses/win_MED.png", 200, 200),
        &assets.loadTexture("../assets/bosses/win_LOW.png", 200, 200),
    };

    Lisp::sharedTextures = {
        &assets.loadTexture("../assets/bosses/lisp_HIGH.png", 200, 200),
        &assets.loadTexture("../assets/bosses/lisp_MED.png", 200, 200),
        &assets.loadTexture("../assets/bosses/lisp_LOW.png", 200, 200),
    };
  }

  MiniBoss *create(MiniBossType type, Vector2 pos) {
    switch (type) {
    case MiniBossType::WINDOWS:
      return MiniBossPool::getFreeMiniBoss<Windows>(pos);

    case MiniBossType::LISP:
      return MiniBossPool::getFreeMiniBoss<Lisp>(pos);

    default:
      std::cerr << "Unknown MiniBoss Type!\n";
      return nullptr;
    }
  }

private:
};
