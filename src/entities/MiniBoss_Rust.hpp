#pragma once

#include "MiniBoss.hpp"

class Rust : public MiniBoss {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Rust() : MiniBoss(MiniBossType::RUST, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float bossCooldown) override {
    stats.pos = {stats.pos.x, stats.pos.y + (sinf(bossCooldown) * .25f)};
  }
};
