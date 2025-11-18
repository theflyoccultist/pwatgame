#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "MiniBoss.hpp"
#include "MiniBossFactory.hpp"
#include "Player.hpp"
#include <memory>
#include <raylib.h>
#include <utility>
#include <vector>

class MiniBossManager {
public:
  MiniBossManager(ProjectileManager &pm) : projMan(pm) {}

  void init() { factory.loadAssets(); };

  void spawnMiniBoss(BossType type) {
    Vector2 pos = {320, 320};
    auto e = factory.create(type, pos);

    if (e)
      miniBosses.push_back(std::move(e));
  };

  void updateAll(float dt, const PlayerState &player) {
    for (auto &m : miniBosses)
      m->update(dt, player.position);

    std::erase_if(miniBosses, [](auto &p) { return !p->isAlive(); });
  };

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
