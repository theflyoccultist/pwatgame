#pragma once

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

    ImmobileWall::sharedTextures = {
        &assets.loadTexture("../assets/enemies/wall_warning.png"),
        &assets.loadTexture("../assets/enemies/wall_appear.png"),
    };

    MovingWall::sharedTextures = {
        &assets.loadTexture("../assets/enemies/wall_warning.png"),
        &assets.loadTexture("../assets/enemies/wall_moving.png"),
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
