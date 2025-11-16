#pragma once

#include "../texture/AssetSystem.hpp"
#include "Actor.hpp"
#include <array>
#include <cstdint>
#include <raylib.h>

enum class BossType : uint8_t { WINDOWS, LISP };

class MiniBoss : public Actor {
protected:
  struct BossStats {
    float speed;
    int hp;
    int size = 200;
  };

  float bossTimer = 0.0f;

public:
  MiniBoss(BossType type, Vector2 pos, BossStats stats,
           const std::array<Texture2D *, 3> &textures)
      : type(type), position(pos), speed(stats.speed), currentHP(stats.hp),
        totalHP(stats.hp), size(stats.size), textures(textures) {}

  BossType type;
  Vector2 position;
  float speed;
  int currentHP;
  int totalHP;
  int size;

  void update(float dt, [[maybe_unused]] Vector2 playerPos) override {
    bossTimer += dt;
  }

  void draw() const override {
    float ratio = static_cast<float>(currentHP) / static_cast<float>(totalHP);
    const Texture2D *tex = chooseTexture(ratio, textures);

    if (tex) {
      AssetSystem::instance().drawTexture(const_cast<Texture2D *>(tex),
                                          (int)position.x, (int)position.y);
    }
  }

  bool isAlive() const { return currentHP > 0; }

protected:
  std::array<Texture2D *, 3> textures;
};
