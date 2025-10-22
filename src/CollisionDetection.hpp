#pragma once

#include "entities/EntityManager.hpp"
#include "items/ItemsManager.hpp"
#include <raylib.h>

namespace Collisions {
bool checkPickup(Vector2 playerPos, const Item &item);
bool checkBulletInteraction(Vector2 bulletPos, const Entity &entity);
bool checkPlayerInteraction(Vector2 playerPos, const Entity &entity);

} // namespace Collisions
