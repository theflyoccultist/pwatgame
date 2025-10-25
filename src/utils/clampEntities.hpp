#include "../Game.hpp"
#include <algorithm>
#include <raylib.h>

class ClampEntities {
public:
  static void clamp(Vector2 &position, int size) {
    position.x =
        std::clamp(position.x, 0.0f, (float)(Game::screenWidth - size));
    position.y =
        std::clamp(position.y, 0.0f, (float)(Game::screenHeight - size));
  }
};
