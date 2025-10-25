#include <array>
#include <cstddef>
#include <raylib.h>

struct PlayerState {
  int texture;
  Vector2 position;
  Vector2 direction;
  static inline int health;
  static inline float damageCooldown = 0.0f;
  static inline float playerSpeed = 500.0f;
  static constexpr int playerSize = 70;
  static inline int score = 0;
  static inline int playerAmmo = 0;
};

class Player {
public:
  Player();
  void draw(Vector2 position, int direction);

  PlayerState playerMovements(PlayerState state, float dt);
  void playerFootsteps();

  static void changePlayerHealth(int value) { PlayerState::health += value; }
  static void addAmmo(int ammo) { PlayerState::playerAmmo += ammo; }

  static void resetPlayerHealth() { PlayerState::health = 50; }
  static void resetPlayerScore() { PlayerState::score = 0; }
  static void resetPlayerAmmo() { PlayerState::playerAmmo = 100; }

private:
  static constexpr std::size_t numPwats = 8;
  std::array<Texture2D *, numPwats> pwatAssets;

  float footstepTimer = 0.0f;
  static constexpr float footstepDelay = 0.44f;
  float shootCooldown = 0.15f;
  float shootTimer = 0.0f;

  void shoot(Vector2 startPosition, Vector2 dir);
};
