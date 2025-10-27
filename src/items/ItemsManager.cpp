#include "ItemsManager.hpp"
#include "../Player.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../utils/Random.hpp"
#include "FeedbackSystem.hpp"
#include <raylib.h>

void ItemManager::addItem(ItemCategory cat, int type, Vector2 pos) {
  itemsByCategory[cat].emplace_back(cat, type, pos);
}

void ItemManager::populateItems() {
  itemsByCategory.clear();

  std::unordered_map<ItemCategory, std::vector<Vector2>> itemPositions = {
      {ItemCategory::Food, {}}, {ItemCategory::Drink, {}}};

  for (auto &[category, positions] : itemPositions) {
    for (size_t i = 0; i < 5; ++i) {
      addItem(
          category, static_cast<int>(i),
          {Random::rangeFloat(0.0f, 730.0f), Random::rangeFloat(0.0f, 730.0f)});
    }
  }
}
void ItemManager::drawItems(ItemCategory cat) {
  auto it = itemsByCategory.find(cat);
  if (it == itemsByCategory.end())
    return;

  for (auto &item : it->second)
    itemsObj.draw(item.category, item.position, item.type);

  FeedbackSystem::instance().draw();
}

void ItemManager::updateItems(const Vector2 &playerPos,
                              const float &playerSize) {
  for (auto &[category, items] : itemsByCategory) {
    for (auto &item : items) {
      if (item.active &&
          Collisions::checkPickup(playerPos, playerSize, item.position,
                                  {item.size.x, item.size.y})) {
        item.active = false;

        switch (item.category) {
        case ItemCategory::Food:
          Player::addAmmo(100);
          FeedbackSystem::instance().addFeedback("+100 AMMO", playerPos);
          break;

        case ItemCategory::Drink:
          Player::changePlayerHealth(50);
          FeedbackSystem::instance().addFeedback("+50 HP", playerPos);
          break;
        }
      }
    }
  }

  FeedbackSystem::instance().update();

  for (auto &[category, items] : itemsByCategory)
    std::erase_if(items, [](const Item &item) { return !item.active; });
}
