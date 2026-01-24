#include "Enemy.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

struct WallState {
  float warningTime;
  float activeTime;
};

class Walled : public Enemy {
public:
  static std::array<Texture2D *, 3> sharedTextures;
  Walled() : Enemy(EnemyType::WALLED, sharedTextures) {}

  void setTexture() override { textures = sharedTextures; }

  void draw() const override {
    if (!isAlive())
      return;

    Texture2D *tex = chooseWallTexture(textureChoice, textures);

    if (!tex) {
      std::cerr << "Wall texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

  void update([[maybe_unused]] ShootParams &p,
              [[maybe_unused]] ProjectileManager &projMan,
              float actorCooldown) override {
    stats.size = 150.0f;

    if (actorCooldown < cs.warningTime) {
      textureChoice = 0;
      deactivateContactDmg();
    }

    else if (actorCooldown < cs.warningTime + cs.activeTime) {
      textureChoice = 1;
      activateContactDmg();
    } else {
      killEntity();
    }
  }

private:
  WallState cs = {3.6f, 2.5f};
  int textureChoice;
  void resetPosition() { stats.pos = stats.initialPos; }
};
