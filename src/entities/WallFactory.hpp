#pragma once

#include <Paths/Paths.hpp>
#include <entities/Wall.hpp>
#include <entities/WallPool.hpp>
#include <entities/WallSpec.hpp>
#include <entities/WallType.hpp>

#include <iostream>
#include <raylib.h>

class WallFactory {
public:
  WallFactory() = default;

  void loadAssets() {
    auto &assets = AssetSystem::instance();
    const fs::path assetsPath = Paths::getAssetsPath();

    ImmobileWall::sharedTextures = {
        &assets.loadTexture(assetsPath / "enemies/wall_warning.png"),
        &assets.loadTexture(assetsPath / "enemies/wall_appear.png"),
    };

    MovingWall::sharedTextures = {
        &assets.loadTexture(assetsPath / "enemies/wall_warning.png"),
        &assets.loadTexture(assetsPath / "enemies/wall_moving.png"),
    };
  }

  Wall *create(WallType type, Vector2 pos, const WallSpec &spec) {
    switch (type) {
    case WallType::IMMOBILE:
      return WallPool::getFreeWall<ImmobileWall>(pos, spec);

    case WallType::MOVING:
      return WallPool::getFreeWall<MovingWall>(pos, spec);

    default:
      std::cerr << "WallFactory.hpp: Wall *create: Unknown Wall type!\n";
      return nullptr;
    }
  }
};
