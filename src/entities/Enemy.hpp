#pragma once

#include "../texture/AssetSystem.hpp"
#include "Actor.hpp"
#include "EnemySpec.hpp"
#include "EnemyType.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

class Enemy : public Actor {
protected:
  struct EnemyStats {
    bool active = false;
    Vector2 pos{};
    float speed = 0.0f;
    int size = 70;
    int currentHP = 0;
    int totalHP = 0;
    int contactDmg = 0;
  };

public:
  Enemy(EnemyType t, const std::array<Texture2D *, 3> &textures)
      : type(t), textures(textures) {}

  EnemyStats stats;
  EnemyType type;

  void reset(Vector2 pos, const EnemySpec &spec) {
    stats.active = true;
    stats.pos = pos;
    stats.speed = spec.speed;
    stats.totalHP = spec.totalHP;
    stats.currentHP = stats.totalHP;
    stats.contactDmg = spec.contactDmg;
  }

  virtual void setTexture() = 0;

  virtual void update(float dt, Vector2 playerPos) = 0;

  void draw() const override {
    if (!isAlive())
      return;

    float ratio =
        static_cast<float>(stats.currentHP) / static_cast<float>(stats.totalHP);
    const Texture2D *tex = chooseTexture(ratio, textures);

    if (!tex) {
      std::cerr << "Enemy texture missing\n";
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
  std::array<Texture2D *, 3> textures{};
};
