#include <array>
#include <cstddef>
#include <raylib.h>

struct PlayerState {
  int texture;
  Vector2 position;
};

class Player {
public:
  static constexpr std::size_t numPwats = 4;
  static constexpr int pwatSize = 70;
  static constexpr float playerSpeed = 3.0f;

  Player();

  PlayerState playerMovements(int current, Vector2 playerPosition);
  void playerFootsteps();

  void draw(Vector2 position, int direction);

private:
  std::array<Texture2D *, numPwats> pwatAssets;

  float footstepTimer = 0.0f;
  static constexpr float footstepDelay = 0.84f;
};
