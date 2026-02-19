#include <collisions/CollisionDetection.hpp>

namespace Collisions {
bool checkPickup(const Vector2 &playerPos, float playerSize,
                 const Vector2 &itemPos, float itemSize) {

  Rectangle playerRect = {playerPos.x, playerPos.y, playerSize, playerSize};
  Rectangle itemRect = {itemPos.x, itemPos.y, itemSize, itemSize};

  return CheckCollisionRecs(playerRect, itemRect);
}

bool checkBulletInteraction(const Vector2 &bulletPos, float bulletSize,
                            const Vector2 &entity, float entitySize) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, bulletSize, bulletSize};
  Rectangle entityRect = {entity.x, entity.y, entitySize, entitySize};

  return CheckCollisionRecs(bulletRect, entityRect);
}

bool checkPlayerInteraction(const Vector2 &playerPos, float playerSize,
                            const Vector2 &enemyPos, float enemySize) {

  Rectangle playerRect = {playerPos.x, playerPos.y, playerSize, playerSize};
  Rectangle entityRect = {enemyPos.x, enemyPos.y, enemySize, enemySize};

  return CheckCollisionRecs(playerRect, entityRect);
}
} // namespace Collisions
