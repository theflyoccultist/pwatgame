#include "ItemsManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../entities/Player.hpp"
#include "../sound/AudioSystem.hpp"
#include "../utils/Random.hpp"
#include "FeedbackSystem.hpp"
#include <raylib.h>

void ItemManager::addItem(ItemCategory cat, int type, Vector2 pos) {
  itemsByCategory[cat].emplace_back(cat, type, pos);
}

void ItemManager::populateItems(int food, int drink) {
  itemsByCategory.clear();

  for (int i = 0; i < food; ++i) {
    addItem(
        ItemCategory::Food, Random::rangeInt(0, 4),
        {Random::rangeFloat(0.0f, 430.0f), Random::rangeFloat(0.0f, 730.0f)});
  }
  for (int i = 0; i < drink; ++i) {
    addItem(
        ItemCategory::Drink, Random::rangeInt(0, 4),
        {Random::rangeFloat(130.0f, 730.0f), Random::rangeFloat(0.0f, 730.0f)});
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

void ItemManager::updateItems(const Vector2 &playerPos, float playerSize) {
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
          AudioSystem::instance().ammoAdded();
          break;

        case ItemCategory::Drink:
          Player::changePlayerHealth(50);
          FeedbackSystem::instance().addFeedback("+50 HP", playerPos);
          AudioSystem::instance().healthAdded();
          break;
        }
      }
    }
  }

  FeedbackSystem::instance().update();

  for (auto &[category, items] : itemsByCategory)
    std::erase_if(items, [](const Item &item) { return !item.active; });
}
