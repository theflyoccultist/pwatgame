#pragma once

#include "../texture/AssetSystem.hpp"
#include "Actor.hpp"
#include "MiniBossType.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

class MiniBoss : public Actor {
protected:
  struct MiniBossStats {
    bool active = false;
    Vector2 pos{};
    float speed = 0.0f;
    int currentHP;
    int totalHP;
    int size = 200;
  };

public:
  MiniBoss(MiniBossType t, const std::array<Texture2D *, 3> &textures)
      : type(t), textures(textures) {}

  MiniBossStats stats;
  MiniBossType type;

  void draw() const override {
    float ratio =
        static_cast<float>(stats.currentHP) / static_cast<float>(stats.totalHP);
    const Texture2D *tex = chooseTexture(ratio, textures);

    if (!tex) {
      std::cerr << "MiniBoss texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(const_cast<Texture2D *>(tex),
                                        (int)stats.pos.x, (int)stats.pos.y);

    DrawRectangle((int)stats.pos.x + 5, (int)stats.pos.y - 15,
                  (int)((float)stats.size * ratio), 10, healthbarColor(ratio));
    DrawRectangleLines((int)stats.pos.x + 5, (int)stats.pos.y - 15, stats.size,
                       10, BLACK);
  }

  bool takeBulletIfHit(int dmg) {
    stats.currentHP -= dmg;
    return stats.currentHP <= 0;
  }

  bool isAlive() const { return stats.currentHP > 0; }
  bool isActive() { return stats.active; }
  void activate() { stats.active = true; }
  void deactivate() { stats.active = false; }

protected:
  std::array<Texture2D *, 3> textures;
};
