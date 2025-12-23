#pragma once

#include "Projectile.hpp"

class Hellfire : public Projectile {
public:
  static Texture2D *projTexture;
  Hellfire()
      : Projectile(Faction::None, ProjectileType::HELLFIRE, projTexture) {}

  void setTexture() override { texture = projTexture; }
};
