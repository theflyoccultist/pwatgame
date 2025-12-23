#pragma once

#include "MiniBoss.hpp"

class Java : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Java() : MiniBoss(MiniBossType::JAVA, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update([[maybe_unused]] ShootParams &p,
              [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(actorCooldown) * .25f)};
  }
};
