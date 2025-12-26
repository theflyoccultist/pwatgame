#include "ItemsManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include <memory>
#include <raylib.h>

void ItemManager::updateAll(const PlayerState &player) {
  for (auto &item : items) {
    if (item->isActive() &&
        Collisions::checkPickup(player.position, player.playerSize,
                                item->stats.pos, item->stats.size)) {
      item->applyToPlayer(player);
    }
  }

  std::erase_if(items,
                [](const auto &ptr) { return !ptr || !ptr->isActive(); });
}

void ItemManager::drawAll() {
  for (auto &item : items)
    item->draw();
}

void ItemManager::clearAll() { items.clear(); }
