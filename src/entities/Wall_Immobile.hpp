#pragma once

#include "Wall.hpp"
#include <array>
#include <raylib.h>

class ImmobileWall : public Wall {
public:
  static std::array<Texture2D *, 2> sharedTextures;
  ImmobileWall() : Wall(WallType::IMMOBILE, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(const WallParams &p) override {
    if (p.wallCooldown < stats.warningTime) {
      deactivateContactDmg();
      textureChoice = 0;
    }

    else if (p.wallCooldown < stats.warningTime + stats.activeTime) {
      activateContactDmg();
      textureChoice = 1;
    } else {
      deactivateContactDmg();
      deactivateWall();
    }
  }
};
