#include "CollisionDetection.hpp"
#include <raylib.h>

namespace Collisions {
bool checkPickup(const Vector2 &playerPos, const Item &item) {

  Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
  Rectangle itemRect = {item.position.x, item.position.y, item.size.x,
                        item.size.y};

  return CheckCollisionRecs(playerRect, itemRect);
}

bool checkBulletInteraction(const Vector2 &bulletPos, const Vector2 &enemy,
                            const float &enemySize) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, 10, 10};
  Rectangle entityRect = {enemy.x, enemy.y, enemySize, enemySize};

  return CheckCollisionRecs(bulletRect, entityRect);
}

bool checkPlayerInteraction(const PlayerState &state, const Vector2 &enemy,
                            const float &enemySize) {

  Rectangle playerRect = {state.position.x, state.position.y, state.playerSize,
                          state.playerSize};
  Rectangle entityRect = {enemy.x, enemy.y, enemySize, enemySize};

  return CheckCollisionRecs(playerRect, entityRect);
}
} // namespace Collisions
