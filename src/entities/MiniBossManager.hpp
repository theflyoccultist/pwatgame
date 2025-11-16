#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include "MiniBoss.hpp"
#include "MiniBossFactory.hpp"
#include <memory>
#include <raylib.h>

class MiniBossManager {
public:
  MiniBossManager(ProjectileManager &pm) : projMan(pm) {}

  void spawnMiniBoss(BossType type) {
    Vector2 pos = {400, 400};
    factory.create(type, pos);
  };

  void updateMiniBoss(float dt) { miniBoss->update(dt, {0, 0}); };
  void drawMiniBoss() { miniBoss->draw(); };

private:
  std::unique_ptr<MiniBoss> miniBoss;
  MiniBossFactory factory;

  ProjectileManager &projMan;
};
