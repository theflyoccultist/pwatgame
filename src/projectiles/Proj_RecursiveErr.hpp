#pragma once

#include "Projectile.hpp"
#include <cmath>
#include <vector>

class RecursiveError : public Projectile {
public:
  static Texture2D *projTexture;
  RecursiveError()
      : Projectile(Faction::None, ProjectileType::RECURSIVEERROR, projTexture) {
  }

  void setTexture() override { texture = projTexture; }

  int depth = 2;

  void onExpire(std::vector<SpawnRequest> &out) override {
    if (depth <= 0)
      return;

    for (int i = 0; i < 3; ++i) {
      float angle = (float)i * 2.0f * PI / 3.0f;

      Vector2 v = {
          std::cosf(angle) * 150.0f,
          std::sinf(angle) * 150.0f,
      };

      out.push_back({

      });
    }
  }
};
