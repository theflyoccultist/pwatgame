#pragma once

#include "../entities/EnemyManager.hpp"
#include "../items/ItemsManager.hpp"
#include <raylib.h>

namespace Collisions {
bool checkPickup(Vector2 playerPos, const Item &item);
bool checkBulletInteraction(Vector2 bulletPos, const Enemy &entity);
bool checkPlayerInteraction(Vector2 playerPos, const Enemy &entity);

} // namespace Collisions
