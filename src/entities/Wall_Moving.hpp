#pragma once

#include "Wall.hpp"
#include <array>
#include <raylib.h>

class MovingWall : public Wall {
public:
  static std::array<Texture2D *, 2> sharedTextures;
  MovingWall() : Wall(WallType::MOVING, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(const WallParams &p) override {
    float &pos =
        (stats.axis == MoveAxis::Horizontal) ? stats.pos.x : stats.pos.y;
    float limit = (stats.axis == MoveAxis::Horizontal)
                      ? (float)GetScreenWidth()
                      : (float)GetScreenHeight();

    pos += stats.speed * p.dt * (float)dir;

    if (pos >= (limit - stats.size))
      dir = -1;
    else if (pos <= 0)
      dir = 1;

    if (p.wallCooldown < stats.warningTime) {
      textureChoice = 0;
      deactivateContactDmg();
    }

    else if (p.wallCooldown < stats.warningTime + stats.activeTime) {
      textureChoice = 1;
      activateContactDmg();
    } else {
      deactivateContactDmg();
      deactivateWall();
    }
  }

private:
  int dir = 1;
};
