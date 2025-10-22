#include "Player.hpp"
#include "entities/EntityManager.hpp"
#include "projectiles/PlayerProjectiles.hpp"
#include <raylib.h>

namespace Collisions {

static bool checkBulletInteraction(Vector2 bulletPos, const Entity &entity) {

  Rectangle bulletRect = {bulletPos.x, bulletPos.y, PlayerProjectiles::size,
                          PlayerProjectiles::size};
  Rectangle entityRect = {entity.position.x, entity.position.y,
                          entity.entitySize, entity.entitySize};

  return CheckCollisionRecs(bulletRect, entityRect);
}

static bool checkPlayerInteraction(Vector2 playerPos, const Entity &entity) {

  Rectangle playerRect = {playerPos.x, playerPos.y, PlayerState::playerSize,
                          PlayerState::playerSize};
  Rectangle entityRect = {entity.position.x, entity.position.y,
                          entity.entitySize, entity.entitySize};

  return CheckCollisionRecs(playerRect, entityRect);
}

} // namespace Collisions
