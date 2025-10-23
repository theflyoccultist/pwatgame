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

bool checkBulletInteraction(Vector2 bulletPos, const Enemy &enemy) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, PlayerProjectiles::size,
                          PlayerProjectiles::size};
  Rectangle entityRect = {enemy.position.x, enemy.position.y, enemy.entitySize,
                          enemy.entitySize};

  return CheckCollisionRecs(bulletRect, entityRect);
}

bool checkPlayerInteraction(Vector2 playerPos, const Enemy &enemy) {

  Rectangle playerRect = {playerPos.x, playerPos.y, PlayerState::playerSize,
                          PlayerState::playerSize};
  Rectangle entityRect = {enemy.position.x, enemy.position.y, enemy.entitySize,
                          enemy.entitySize};

  return CheckCollisionRecs(playerRect, entityRect);
}
} // namespace Collisions
