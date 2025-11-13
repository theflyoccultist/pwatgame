#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "../texture/AssetSystem.hpp"
#include "../utils/Random.hpp"
#include "../utils/clampEntities.hpp"
#include <array>
#include <raylib.h>

enum class EnemyType { SWARMER, SNIPER, ZOMB, GODSIP, GOST };

struct ShootParams {
  Vector2 startPos;
  Vector2 playerPos;
  float dt;
  float cooldown;
  ProjectileType type;
};

class Enemy {
private:
  float shootTimer = 0.0f;
  const bool isX = Random::chance(.5f);
  void shoot(ProjectileManager &pm, const ShootParams &p,
             const Vector2 &direction);

public:
  Enemy(EnemyType type, Vector2 pos, float spd, int hp, int sz,
        const std::array<Texture2D *, 3> &textures)
      : type(type), position(pos), speed(spd), currentHP(hp), totalHP(hp),
        size(sz), textures(textures) {}

  virtual ~Enemy() = default;
  virtual void update(float delta, Vector2 playerPos) = 0;

  virtual void draw() const {
    if (!isAlive())
      return;

    float ratio = static_cast<float>(currentHP) / static_cast<float>(totalHP);
    const Texture2D *tex = chooseTexture(ratio);

    if (tex) {
      AssetSystem::instance().drawTexture(const_cast<Texture2D *>(tex),
                                          position.x, position.y);
    }

    DrawRectangle(position.x + 5, position.y - 15, 50 * ratio, 10,
                  healthbarColor(ratio));
    DrawRectangleLines(position.x + 5, position.y - 15, 50, 10, BLACK);
  }

  bool takeBulletIfHit(int dmg);

  bool isAlive() const { return currentHP > 0; }

  void shootTowardsPlayer(ProjectileManager &pm, const ShootParams &p);
  void shootInVoid(ProjectileManager &pm, const ShootParams &p);

  EnemyType type;
  Vector2 position;
  float speed;
  int currentHP;
  int totalHP;
  int size;

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
    Color health = GREEN;
    if (ratio < 0.66)
      health = YELLOW;
    if (ratio <= 0.33)
      health = RED;
    return health;
  }

  std::array<Texture2D *, 3> textures;
};
