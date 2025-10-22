#include "CollisionDetection.hpp"
#include "../projectiles/PlayerProjectiles.hpp"

namespace Collisions {
bool checkPickup(Vector2 playerPos, const Item &item) {

  Rectangle playerRect = {playerPos.x, playerPos.y, PlayerState::playerSize,
                          PlayerState::playerSize};
  Rectangle itemRect = {item.position.x, item.position.y, item.size.x,
                        item.size.y};

  return CheckCollisionRecs(playerRect, itemRect);
}

bool checkBulletInteraction(Vector2 bulletPos, const Entity &entity) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, PlayerProjectiles::size,
                          PlayerProjectiles::size};
  Rectangle entityRect = {entity.position.x, entity.position.y,
                          entity.entitySize, entity.entitySize};

  return CheckCollisionRecs(bulletRect, entityRect);
}

bool checkPlayerInteraction(Vector2 playerPos, const Entity &entity) {

  Rectangle playerRect = {playerPos.x, playerPos.y, PlayerState::playerSize,
                          PlayerState::playerSize};
  Rectangle entityRect = {entity.position.x, entity.position.y,
                          entity.entitySize, entity.entitySize};

  return CheckCollisionRecs(playerRect, entityRect);
}
} // namespace Collisions
