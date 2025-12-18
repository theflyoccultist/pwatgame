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

  static void addHealth(int value) { PlayerState::health += value; }
  static void addAmmo(int ammo) { PlayerState::playerAmmo += ammo; }
  static void upgradeAmmo(ProjectileType newWeapon) {
    PlayerState::currWeapon = newWeapon;
  }

  void applyPlayerDmg(float delta, int damage) const {
    if (PlayerState::damageCooldown > 0.0f)
      PlayerState::damageCooldown -= delta;

    if (PlayerState::damageCooldown <= 0.0f) {
      PlayerState::health -= damage;
      PlayerState::damageCooldown = 0.50f;
    }
  }
};
