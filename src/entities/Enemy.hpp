#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "../texture/AssetSystem.hpp"
#include "../utils/Random.hpp"
#include "../utils/clampEntities.hpp"
#include "Actor.hpp"
#include <array>
#include <cstdint>
#include <raylib.h>

enum class EnemyType : uint8_t { SWARMER, SNIPER, ZOMB, GODSIP, GOST, COUNT };

class Enemy : public Actor {
protected:
  struct EnemyStats {
    float speed;
    int hp;
    int size = 70;
  };

  struct ShootParams {
    Vector2 startPos;
    Vector2 playerPos;
    float dt;
    float cooldown;
    ProjectileType type;
  };

private:
  float shootTimer = 0.0f;
  const bool isX = Random::chance(.5f);
  void shoot(ProjectileManager &pm, const ShootParams &p,
             const Vector2 &direction);

public:
  Enemy(EnemyType type, Vector2 pos, EnemyStats stats,
        const std::array<Texture2D *, 3> &textures)
      : type(type), position(pos), speed(stats.speed), currentHP(stats.hp),
        totalHP(stats.hp), size(stats.size), textures(textures) {}

  EnemyType type;
  Vector2 position;
  float speed;
  int currentHP;
  int totalHP;
  int size;

  void update(float dt, Vector2 playerPos) override = 0;

  void draw() const override {
    if (!isAlive())
      return;

    float ratio = static_cast<float>(currentHP) / static_cast<float>(totalHP);
    const Texture2D *tex = chooseTexture(ratio);

    if (tex) {
      AssetSystem::instance().drawTexture(const_cast<Texture2D *>(tex),
                                          (int)position.x, (int)position.y);
    }

    DrawRectangle((int)position.x + 5, (int)position.y - 15,
                  (int)((float)size * ratio), 10, healthbarColor(ratio));
    DrawRectangleLines((int)position.x + 5, (int)position.y - 15, size, 10,
                       BLACK);
  }

  bool takeBulletIfHit(int dmg);

  bool isAlive() const { return currentHP > 0; }

  void shootTowardsPlayer(ProjectileManager &pm, const ShootParams &p);
  void shootInVoid(ProjectileManager &pm, const ShootParams &p);

protected:
  const Texture2D *chooseTexture(float ratio) const {
    if (textures[0] == nullptr)
      return nullptr;
    if (ratio > 0.66f)
      return textures[0];
    if (ratio > 0.33f)
      return textures[1];
    return textures[2];
  }

  const Color healthbarColor(float ratio) const {
    if (ratio > 0.66f)
      return GREEN;
    if (ratio > 0.33f)
      return YELLOW;
    return RED;
  }

  std::array<Texture2D *, 3> textures;
};
