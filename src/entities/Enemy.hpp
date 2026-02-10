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
    Vector2 initialPos{};
    float speed;
    float size;
    int currentHP;
    int totalHP;
    int contactDmg;
    int initialContactDmg;
  };

public:
  Enemy(EnemyType t, const std::array<Texture2D *, 3> &textures)
      : type(t), textures(textures) {}

  EnemyStats stats;
  EnemyType type;

  void reset(const Vector2 &startPos, const EnemySpec &spec) {
    stats.active = true;
    stats.pos = startPos;
    stats.initialPos = startPos;
    stats.speed = spec.speed;
    stats.size = spec.size;
    stats.totalHP = spec.totalHP;
    stats.currentHP = stats.totalHP;
    stats.contactDmg = spec.contactDmg;
    stats.initialContactDmg = spec.contactDmg;
  }

  virtual void setTexture() = 0;

  void draw() const override {
    if (!isAlive())
      return;

    float ratio =
        static_cast<float>(stats.currentHP) / static_cast<float>(stats.totalHP);
    Texture2D *tex = chooseTexture(ratio, textures);

    if (!tex) {
      std::cerr << "Enemy texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);

    DrawRectangle((int)stats.pos.x + 5, (int)stats.pos.y - 15,
                  (int)((float)stats.size * ratio), 10, healthbarColor(ratio));
    DrawRectangleLines((int)stats.pos.x + 5, (int)stats.pos.y - 15,
                       (int)stats.size, 10, BLACK);
  }

  bool takeBulletIfHit(int dmg) {
    stats.currentHP -= dmg;
    return stats.currentHP <= 0;
  }

  bool isAlive() const { return stats.currentHP > 0; }
  void killEntity() { stats.currentHP = 0; }
  bool isActive() { return stats.active; }
  void activate() { stats.active = true; }
  void deactivate() { stats.active = false; }

  void deactivateContactDmg() { stats.contactDmg = 0; }
  void activateContactDmg() { stats.contactDmg = stats.initialContactDmg; }

protected:
  std::array<Texture2D *, 3> textures{};
};
