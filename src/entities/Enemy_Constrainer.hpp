#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <array>
#include <raylib.h>

// struct ConstrainerState {
//   float warningTime = 3.6f;
//   float activeTime = 2.5f;
//   int dirY = 1;
// };
//
// class Constrainer : public Enemy {
// public:
//   static std::array<Texture2D *, 3> sharedTextures;
//   Constrainer() : Enemy(EnemyType::CONSTRAINER, sharedTextures) {}
//
//   void setTexture() override { textures = sharedTextures; }
//
//   void update(ShootParams &p, ProjectileManager &projMan,
//               float actorCooldown) override {
//
//     stats.pos.y += stats.speed * p.dt * (float)cs.dirY;
//     if (stats.pos.y >= 730.f)
//       cs.dirY = -1;
//     else if (stats.pos.y <= 0)
//       cs.dirY = 1;
//
//     if (actorCooldown < cs.warningTime) {
//       deactivateContactDmg();
//
//       std::cout << "Contact damage is off" << "\n";
//
//       p.type = ProjectileType::INTERNET;
//       p.spec = EnemyDatabase::getWeaponSpec(p.type);
//       shootTowardsPlayer(projMan, p);
//     }
//
//     if (actorCooldown < cs.warningTime + cs.activeTime) {
//
//       std::cout << "Contact damage is on" << "\n";
//       resetPosition();
//       activateContactDmg();
//
//       // stats.pos.x += (stats.initialPos.x - stats.pos.x) * 0.25f;
//       // stats.pos.y += (stats.initialPos.y - stats.pos.y) * 0.25f;
//
//     } else {
//       killEntity();
//     }
//   }
//
// private:
//   ConstrainerState cs;
//   void resetPosition() { stats.pos = stats.initialPos; }
// };
//

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
      stats.pos.y -=
          std::sinf(actorCooldown) * stats.speed * p.dt * (float)dirY;
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
