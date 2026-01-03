#pragma once

#include "../entities/Faction.hpp"
#include "../texture/AssetSystem.hpp"
#include "ProjectileType.hpp"
#include "WeaponSpec.hpp"
#include <iostream>
#include <raylib.h>

inline const char *toString(ProjectileType type) {
  switch (type) {
  case ProjectileType::STRAIGHT:
    return "STRAIGHT";
  case ProjectileType::LONGRANGE:
    return "LONGRANGE";
  case ProjectileType::SLOWCANNON:
    return "SLOWCANNON";
  case ProjectileType::ROCKET:
    return "ROCKET";
  case ProjectileType::UZI:
    return "UZI";
  case ProjectileType::GRENADE:
    return "GRENADE";
  case ProjectileType::HELLFIRE:
    return "HELLFIRE";
  default:
    return "UNKNOWN_PROJECTILE";
  }
}

struct SpawnRequest {
  Faction faction;
  ProjectileType type;
  Vector2 startPos;
  Vector2 direction;
  WeaponSpec spec;
};

class Projectile {
protected:
  struct ProjectileStats {
    bool active = false;
    Vector2 pos{};
    Vector2 dir{};
    Vector2 vel{};
    float cooldown;
    float size;
    float lifetime;
    int damage;
  };

public:
  ProjectileStats stats;
  Faction faction;
  ProjectileType type;
  Texture2D *texture;

  Projectile(Faction f, ProjectileType t, Texture2D *&texture)
      : faction(f), type(t), texture(texture) {}

  virtual ~Projectile() = default;

  virtual void update(float dt, [[maybe_unused]] float bulletTime) {
    stats.pos.x += stats.vel.x * dt;
    stats.pos.y += stats.vel.y * dt;
    stats.lifetime -= dt;
  };

  virtual void draw() const {
    if (!isActive())
      return;

    if (!texture) {
      std::cerr << "Projectile texture missing\n";
      return;
    }

    AssetSystem::instance().drawTexture(texture, stats.pos.x, stats.pos.y,
                                        stats.size);
  }

  virtual void setTexture() = 0;

  void reset(Faction f, Vector2 pos, Vector2 dir, const WeaponSpec &spec) {
    stats.active = true;
    faction = f;
    stats.pos = pos;
    stats.dir = dir;
    stats.vel = {dir.x * (float)spec.speed, dir.y * (float)spec.speed};
    stats.cooldown = spec.fireRate;
    stats.size = spec.size;
    stats.lifetime = spec.lifetime;
    stats.damage = spec.damage;
  }

  void expire() { stats.lifetime = 0.0f; }

  bool isActive() const { return stats.active; }
  void deactivate() { stats.active = false; }
};
