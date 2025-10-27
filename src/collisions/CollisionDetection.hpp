#pragma once

#include <raylib.h>

namespace Collisions {
bool checkPickup(const Vector2 &playerPos, float playerSize,
                 const Vector2 &itemPos, const Vector2 &itemSize);
bool checkBulletInteraction(const Vector2 &bulletPos, float bulletSize,
                            const Vector2 &entity, float enemySize);
bool checkPlayerInteraction(const Vector2 &playerPos, float playerSize,
                            const Vector2 &enemyPos, float enemySize);

} // namespace Collisions
