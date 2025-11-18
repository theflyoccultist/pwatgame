#pragma once

#include "../player/Player.hpp"
#include "../projectiles/ProjectileManager.hpp"
#include "MiniBoss.hpp"
#include "MiniBossFactory.hpp"
#include <memory>
#include <raylib.h>
#include <span>

class MiniBossManager {
public:
  MiniBossManager(ProjectileManager &pm) : projMan(pm) {}

  void init() { factory.loadAssets(); };

  void spawnMiniBoss(BossType type);

  bool updateAll(float dt, const PlayerState &player,
                 std::span<Projectile *const> bullets);

  void drawAll() {
    for (auto &m : miniBosses)
      m->draw();
  };

  void clearAll() { miniBosses.clear(); }

private:
  std::vector<std::unique_ptr<MiniBoss>> miniBosses;
  MiniBossFactory factory;

  ProjectileManager &projMan;
};
