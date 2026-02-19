#pragma once

#include <entities/Enemy.hpp>
#include <entities/EnemyDatabase.hpp>

class Constrainer : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Constrainer() : Enemy(EnemyType::CONSTRAINER, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, ProjectileManager &projMan,
              float actorCooldown) override {

    if (inFireWindow(actorCooldown, 0.8f, 0.35f)) {
      p.type = ProjectileType::ELIXIR;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootTowardsPlayer(projMan, p);
    } else {
      stats.pos.x += stats.speed * p.dt * (float)dirX;
      if (stats.pos.x >= 730.f)
        dirX = -1;
      else if (stats.pos.x <= 0)
        dirX = 1;
      stats.pos.y -= std::sin(actorCooldown) * stats.speed * p.dt * (float)dirY;
      if (stats.pos.y >= 530.0f)
        dirY = -1;
      else if (stats.pos.y <= 0)
        dirY = 1;
    }

    if (actorCooldown >= 7.8f) {
      killEntity();
    }
  }

private:
  int dirX = 1;
  int dirY = 1;

  bool inFireWindow(float t, float period, float duty) {
    float phase = std::fmodf(t, period);
    return phase < (period * duty);
  }
};
