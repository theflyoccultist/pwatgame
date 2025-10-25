#include "CollisionDetection.hpp"
#include <raylib.h>

namespace Collisions {
bool checkPickup(Vector2 playerPos, const Item &item) {

  Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
  Rectangle itemRect = {item.position.x, item.position.y, item.size.x,
                        item.size.y};

  return CheckCollisionRecs(playerRect, itemRect);
}

bool checkBulletInteraction(Vector2 bulletPos, const Vector2 &enemy) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, 10, 10};
  Rectangle entityRect = {enemy.x, enemy.y, 70, 70};

  return CheckCollisionRecs(bulletRect, entityRect);
}

bool checkPlayerInteraction(const Vector2 &playerPos, const Vector2 &enemy) {

  Rectangle playerRect = {playerPos.x, playerPos.y, 70, 70};
  Rectangle entityRect = {enemy.x, enemy.y, 70, 70};

  return CheckCollisionRecs(playerRect, entityRect);
}
} // namespace Collisions
