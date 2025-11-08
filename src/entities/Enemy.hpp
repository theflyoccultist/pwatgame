#pragma once

#include "../texture/AssetSystem.hpp"
#include "../utils/Random.hpp"
#include "../utils/clampEntities.hpp"
#include <array>
#include <raylib.h>

enum class EnemyType { SWARMER, SNIPER, GODSIP, COUNT };

class Enemy {
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
    const Texture2D *tex = chooseTexture();

    if (tex) {
      AssetSystem::instance().drawTexture(const_cast<Texture2D *>(tex),
                                          position.x, position.y);
    }
    DrawText(TextFormat("%d / %d", currentHP, totalHP), position.x + 20,
             position.y - 20, 10, BLACK);
  }

  bool takeBulletIfHit(int dmg);

  bool isAlive() const { return currentHP > 0; }

  void shootTowardsPlayer(const Vector2 &startPos, const Vector2 &playerPos,
                          float dt);

  EnemyType type;
  Vector2 position;
  float speed;
  int currentHP;
  int totalHP;
  int size;

protected:
  const Texture2D *chooseTexture() const {
    if (textures[0] == nullptr)
      return nullptr;

    float ratio = static_cast<float>(currentHP) / static_cast<float>(totalHP);
    if (ratio > 0.66f)
      return textures[0];
    if (ratio > 0.33f)
      return textures[1];
    return textures[2];
  }

  std::array<Texture2D *, 3> textures;

private:
  float shootCooldown = 3.0f;
  float shootTimer = 0.0f;
  void shoot(const Vector2 &startPosition, const Vector2 &dir, float dt);
};
