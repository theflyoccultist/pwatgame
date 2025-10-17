#include <array>
#include <cstddef>
#include <raylib.h>

struct PlayerState {
  int texture;
  Vector2 position;
};

class Player {
public:
  static constexpr std::size_t numPwats = 8;
  static constexpr int pwatSize = 70;
  static constexpr float playerSpeed = 3.0f;

  Player();

  void draw(Vector2 position, int direction);

  PlayerState playerMovements(int current, Vector2 playerPosition);
  void playerFootsteps();

private:
  std::array<Texture2D *, numPwats> pwatAssets;
  float footstepTimer = 0.0f;
  static constexpr float footstepDelay = 0.84f;
};
