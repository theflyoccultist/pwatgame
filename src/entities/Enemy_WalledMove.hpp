#pragma once

#include "Enemy.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

struct WallMoveState {
  float warningTime;
  float activeTime;
};

enum class MoveAxis : uint8_t { Horizontal, Vertical };

class WalledMove : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  WalledMove() : Enemy(EnemyType::WALLEDMOVE, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void draw() const override {
    if (!isAlive())
      return;

    Texture2D *tex = chooseWallTexture(textureChoice, textures);

    if (!tex) {
      std::cerr << "Wall w Movement texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

  MoveAxis axis = MoveAxis::Horizontal;

  void update(ShootParams &p, [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {
    stats.size = 100.0f;

    float &pos = (axis == MoveAxis::Horizontal) ? stats.pos.x : stats.pos.y;
    float limit = (axis == MoveAxis::Horizontal) ? (float)GetScreenWidth()
                                                 : (float)GetScreenHeight();

    pos += stats.speed * p.dt * dirX;

    if (pos >= (limit - stats.size))
      dirX = -1;
    else if (pos <= 0)
      dirX = 1;

    if (actorCooldown < cs.warningTime) {
      textureChoice = 0;
      deactivateContactDmg();
    }

    else if (actorCooldown < cs.warningTime + cs.activeTime) {
      textureChoice = 1;
      activateContactDmg();
    }
  }

private:
  WallMoveState cs = {4.0f, 4.0f};
  int textureChoice;
  void resetPosition() { stats.pos = stats.initialPos; }
  float dirX = 1;
};
