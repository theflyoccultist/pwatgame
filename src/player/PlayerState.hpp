#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include <raylib.h>

struct PlayerState {
  int texture;
  Vector2 position;
  Vector2 direction;
  static inline ProjectileType currWeapon = ProjectileType::STRAIGHT;
  static inline WeaponSpec currentWeaponSpec{};
  static inline int health;
  static inline float damageCooldown = 0.0f;
  static inline float playerSpeed = 600.0f;
  static constexpr int playerSize = 70;
  static inline int score = 0;
  static inline int playerAmmo = 0;

  void addHealth(int value) const { health += value; }
  void addAmmo(int ammo) const { playerAmmo += ammo; }
  void addScore(int score) const { score += score; }

  void upgradeAmmo(ProjectileType newWeapon) const { currWeapon = newWeapon; }

  void updateDamageCooldown(float dt) {
    if (damageCooldown > 0.0f)
      damageCooldown -= dt;
  }

  bool tryApplyPlayerDmg(int damage) const {
    if (damageCooldown > 0.0f)
      return false;

    health -= damage;
    damageCooldown = 0.30f;
    return true;
  }
};
