#pragma once

#include <Paths/Paths.hpp>
#include <entities/MiniBoss.hpp>
#include <entities/MiniBossPool.hpp>

#include <iostream>
#include <raylib.h>

class MiniBossFactory {

public:
  MiniBossFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();
    const fs::path assetsPath = Paths::getAssetsPath();

    Windows::sharedTextures = {
        &assets.loadTexture((assetsPath / "bosses/win_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "bosses/win_MED.png").string()),
        &assets.loadTexture((assetsPath / "bosses/win_LOW.png").string()),
    };

    Lisp::sharedTextures = {
        &assets.loadTexture((assetsPath / "bosses/lisp_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "bosses/lisp_MED.png").string()),
        &assets.loadTexture((assetsPath / "bosses/lisp_LOW.png").string()),
    };

    Java::sharedTextures = {
        &assets.loadTexture((assetsPath / "bosses/java_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "bosses/java_MED.png").string()),
        &assets.loadTexture((assetsPath / "bosses/java_LOW.png").string()),
    };

    Rust::sharedTextures = {
        &assets.loadTexture((assetsPath / "bosses/rust_HIGH.png").string()),
        &assets.loadTexture((assetsPath / "bosses/rust_MED.png").string()),
        &assets.loadTexture((assetsPath / "bosses/rust_LOW.png").string()),
    };
  }

  MiniBoss *create(MiniBossType type, Vector2 pos, const MiniBossSpec &spec) {
    switch (type) {
    case MiniBossType::WINDOWS:
      return MiniBossPool::getFreeMiniBoss<Windows>(pos, spec);

    case MiniBossType::LISP:
      return MiniBossPool::getFreeMiniBoss<Lisp>(pos, spec);

    case MiniBossType::JAVA:
      return MiniBossPool::getFreeMiniBoss<Java>(pos, spec);

    case MiniBossType::RUST:
      return MiniBossPool::getFreeMiniBoss<Rust>(pos, spec);

    default:
      std::cerr << "Unknown MiniBoss Type!\n";
      return nullptr;
    }
  }
};
