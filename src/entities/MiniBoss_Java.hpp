#pragma once

#include "MiniBoss.hpp"

class Java : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Java() : MiniBoss(MiniBossType::JAVA, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};
  }
};
