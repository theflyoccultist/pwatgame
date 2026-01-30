#pragma once

#include "../player/PlayerState.hpp"
#include "../projectiles/ProjectileManager.hpp"
#include "MiniBoss.hpp"
#include "MiniBossFactory.hpp"
#include <array>
#include <raylib.h>
#include <span>

class MiniBossManager {
public:
  MiniBossManager(ProjectileManager &pm) : projMan(pm) {}

  void init() { factory.loadAssets(); };

  void spawnMiniBoss(MiniBossType type);

  bool updateAll(float dt, const PlayerState &player,
                 std::span<Projectile *const> bullets);

  void drawAll() {
    for (auto *m : miniBosses)
      if (m && m->isAlive())
        m->draw();
  };

  void clearAll() {
    for (auto *&m : miniBosses) {
      if (m) {
        m->deactivate();
        m = nullptr;
      }
    }
  }

  void resetTimer() { miniBossTimer = 0.0f; }

private:
  float miniBossTimer = 0.0f;
  static constexpr int MINIBOSS_POOL = 10;
  std::array<MiniBoss *, MINIBOSS_POOL> miniBosses{};
  MiniBossFactory factory;

  ProjectileManager &projMan;
  Actor::ShootParams p;
};
