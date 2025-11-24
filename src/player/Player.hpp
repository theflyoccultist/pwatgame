#pragma once

#include "../projectiles/ProjectileManager.hpp"
#include <array>
#include <cstddef>
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
};

class Player {
public:
  Player(ProjectileManager &pm) : projMan(pm) {}
  void init();
  void draw(Vector2 position, int direction);

  PlayerState playerMovements(PlayerState state, float dt);
  void playerFootsteps(float dt);

  static void addHealth(int value) { PlayerState::health += value; }
  static void addAmmo(int ammo) { PlayerState::playerAmmo += ammo; }
  static void upgradeAmmo(ProjectileType newWeapon) {
    PlayerState::currWeapon = newWeapon;
  }

  static void resetPlayerHealth() { PlayerState::health = 200; }
  static void resetPlayerScore() { PlayerState::score = 0; }
  static void resetPlayerAmmo() { PlayerState::playerAmmo = 500; }
  static void resetDefaultWeapon() {
    PlayerState::currWeapon = ProjectileType::STRAIGHT;
  }

private:
  static constexpr std::size_t numPwats = 8;
  std::array<Texture2D *, numPwats> pwatAssets;

  float footstepTimer = 0.0f;
  static constexpr float footstepDelay = 0.44f;
  float shootTimer = 0.0f;
  const float pwatCenter = static_cast<float>(PlayerState::playerSize / 2.0);
  void shoot(Vector2 startPosition, Vector2 dir);

  ProjectileManager &projMan;
};
