#pragma once

#include "../Player.hpp"
#include "../items/ItemsManager.hpp"
#include <raylib.h>

namespace Collisions {
bool checkPickup(const Vector2 &playerPos, const Item &item);
bool checkBulletInteraction(const Vector2 &bulletPos, const Vector2 &enemy,
                            const float &enemySize);
bool checkPlayerInteraction(const PlayerState &state, const Vector2 &enemy,
                            const float &enemySize);

} // namespace Collisions
