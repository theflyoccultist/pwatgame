#pragma once

#include "../projectiles/ProjectileType.hpp"
#include "../projectiles/WeaponSpec.hpp"
#include <raylib.h>

struct PlayerState {
  int texture;
  Vector2 position;
  Vector2 direction;
  float playerSpeed;

  static constexpr int playerSize = 70;

  static inline ProjectileType currWeapon = ProjectileType::STRAIGHT;
  static inline WeaponSpec currentWeaponSpec{};

  void upgradeAmmo(ProjectileType newWeapon) const { currWeapon = newWeapon; }

  static inline float damageCooldown = 0.0f;

  static inline int playerHealth;
  static inline int playerScore;
  static inline int playerAmmo;

  void addHealth(int health) const { playerHealth += health; }
  void addScore(int score) const { playerScore += score; }
  void addAmmo(int ammo) const { playerAmmo += ammo; }

  void updateDamageCooldown(float dt) const {
    if (damageCooldown > 0.0f)
      damageCooldown -= dt;
  }

  bool tryApplyPlayerDmg(int damage) const {
    if (damageCooldown > 0.0f)
      return false;

    playerHealth -= damage;
    damageCooldown = 0.15f;
    return true;
  }
};
