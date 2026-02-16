#pragma once

#include "../texture/AssetSystem.hpp"
#include "WallAxis.hpp"
#include "WallSpec.hpp"
#include "WallType.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

struct WallConfig {
  bool active = false;
  bool collision = false;
  MoveAxis axis;
  Vector2 pos;
  Vector2 initialPos;
  float speed;
  float size;
  float warningTime;
  float activeTime;
  int contactDmg;
  int initialContactDmg;
};

struct WallParams {
  float dt;
  float wallCooldown;
};

class Wall {
public:
  Wall(WallType t, const std::array<Texture2D *, 2> &textures)
      : type(t), textures(textures) {}

  WallConfig stats;
  WallType type;

  void reset(const Vector2 &startPos, const WallSpec &spec) {
    stats.active = true;
    stats.collision = false;
    stats.axis = spec.axis;
    stats.pos = startPos;
    stats.initialPos = startPos;
    stats.speed = spec.speed;
    stats.size = spec.size;
    stats.warningTime = spec.warningTime;
    stats.activeTime = spec.activeTime;
    stats.contactDmg = spec.contactDmg;
    stats.initialContactDmg = spec.contactDmg;
  };

  virtual void setTexture() = 0;

  void draw() {
    if (!isActive())
      return;

    Texture2D *tex = chooseWallTexture(textureChoice, textures);

    if (!tex) {
      std::cerr << "Wall textures are missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(tex, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

  virtual void update(const WallParams &p) = 0;

  bool isActive() { return stats.active; }
  void deactivateContactDmg() { stats.contactDmg = 0; }
  void activateContactDmg() { stats.contactDmg = stats.initialContactDmg; }
  void deactivateCollision() { stats.collision = false; }
  void activateCollision() { stats.collision = true; }
  void deactivateWall() { stats.active = false; }

protected:
  std::array<Texture2D *, 2> textures{};
  int textureChoice;

  Texture2D *
  chooseWallTexture(int choice,
                    const std::array<Texture2D *, 2> &textures) const {
    if (textures[0] == nullptr)
      return nullptr;
    if (choice == 0)
      return textures[0];
    if (choice == 1)
      return textures[1];
    else
      return textures[0];
  }
};
