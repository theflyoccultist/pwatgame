#pragma once

#include "Actor.hpp"
#include <array>
#include <cstdint>
#include <raylib.h>

enum class BossType : uint8_t { WINDOWS, LISP };

class MiniBoss : public Actor {
protected:
  BossType type;

  Vector2 position;

  struct BossStats {
    float speed;
    int hp;
    int size = 200;
  };

  BossStats stats;

  std::array<Texture2D *, 3> textures;

  float bossTimer = 0.0f;

public:
  MiniBoss(BossType type, Vector2 pos, BossStats stats,
           const std::array<Texture2D *, 3> &textures)
      : type(type), stats(stats), textures(textures) {
    position = pos;
  }

  void update(float dt, Vector2 playerPOs) override;

  virtual void draw() const override;
};
