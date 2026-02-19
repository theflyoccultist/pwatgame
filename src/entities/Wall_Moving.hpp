#pragma once

#include <entities/Wall.hpp>

#include <array>
#include <raylib.h>

class MovingWall : public Wall {
public:
  static std::array<Texture2D *, 2> sharedTextures;
  MovingWall() : Wall(WallType::MOVING, sharedTextures) {}

  void setTexture() override { wallTextures = sharedTextures; }

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
      deactivateContactDmg();
      deactivateCollision();
      textureChoice = 0;
    }

    else if (p.wallCooldown < stats.warningTime + stats.activeTime) {
      activateContactDmg();
      activateCollision();
      textureChoice = 1;
    } else {
      deactivateContactDmg();
      deactivateCollision();
      deactivateWall();
    }
  }

private:
  int dir = 1;
};
