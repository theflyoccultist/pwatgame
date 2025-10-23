#pragma once

#include "../items/ItemsManager.hpp"
#include <raylib.h>

namespace Collisions {
bool checkPickup(Vector2 playerPos, const Item &item);
bool checkBulletInteraction(Vector2 bulletPos, const Vector2 &enemy);
bool checkPlayerInteraction(const Vector2 &playerPos, const Vector2 &enemy);

} // namespace Collisions
