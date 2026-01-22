#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <cmath>
#include <raylib.h>

class Miku : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Miku() : Enemy(EnemyType::MIKU, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void update(ShootParams &p, [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {
    if (actorCooldown <= 2.0f) {
      p.type = ProjectileType::ELIXIR;
      p.spec = EnemyDatabase::getWeaponSpec(p.type);
      shootDiagonally(projMan, p);
    }

    if (actorCooldown >= 2.0f) {
      stats.pos.x -= std::cosf(actorCooldown) * stats.speed * p.dt;
      stats.pos.y -= std::sinf(actorCooldown) * stats.speed * p.dt;
    }
  }
};
