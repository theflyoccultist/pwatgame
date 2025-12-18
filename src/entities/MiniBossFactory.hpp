#pragma once

#include "MiniBoss.hpp"
#include "MiniBossPool.hpp"
#include "MiniBossSpec.hpp"
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
        &assets.loadTexture("../assets/bosses/win_HIGH.png"),
        &assets.loadTexture("../assets/bosses/win_MED.png"),
        &assets.loadTexture("../assets/bosses/win_LOW.png"),
    };

    Lisp::sharedTextures = {
        &assets.loadTexture("../assets/bosses/lisp_HIGH.png"),
        &assets.loadTexture("../assets/bosses/lisp_MED.png"),
        &assets.loadTexture("../assets/bosses/lisp_LOW.png"),
    };

    Java::sharedTextures = {
        &assets.loadTexture("../assets/bosses/java_HIGH.png"),
        &assets.loadTexture("../assets/bosses/java_MED.png"),
        &assets.loadTexture("../assets/bosses/java_LOW.png"),
    };

    Rust::sharedTextures = {
        &assets.loadTexture("../assets/bosses/rust_HIGH.png"),
        &assets.loadTexture("../assets/bosses/rust_MED.png"),
        &assets.loadTexture("../assets/bosses/rust_LOW.png"),
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
