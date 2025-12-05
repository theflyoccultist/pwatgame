#pragma once

#include "MiniBoss.hpp"

class Java : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Java() : MiniBoss(MiniBossType::JAVA, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update([[maybe_unused]] float dt, [[maybe_unused]] Vector2 playerPos,
              float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};
  }
};
