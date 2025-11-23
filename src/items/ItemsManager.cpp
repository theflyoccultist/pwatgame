#include "ItemsManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../player/Player.hpp"
#include "../sound/AudioSystem.hpp"
#include "../utils/Random.hpp"
#include "FeedbackSystem.hpp"
#include <iostream>
#include <raylib.h>

void ItemManager::addItem(ItemCategory cat, int asset, Vector2 pos) {
  itemsByCategory[cat].emplace_back(cat, asset, pos);
}

void ItemManager::populateItems(ItemCategory cat, Vector2 pos) {
  itemsByCategory.clear();

  addItem(cat, Random::rangeInt(0, 4), pos);
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
          AudioSystem::instance().sfx->ammoAdded();
          break;

        case ItemCategory::Drink:
          Player::addHealth(100);
          FeedbackSystem::instance().addFeedback("+100 HP", playerPos);
          AudioSystem::instance().sfx->healthAdded();
          break;

        case ItemCategory::Weapon:
          auto p = static_cast<ProjectileType>(
              Random::rangeInt(0, static_cast<int>(ProjectileType::COUNT) - 1));
          std::cout << "Picked projectile type: " << p << '\n';
          Player::upgradeAmmo(p);

          FeedbackSystem::instance().addFeedback("Weapon Upgraded", playerPos);
          AudioSystem::instance().sfx->newWeapon();
          break;
        }
      }
    }
  }

  FeedbackSystem::instance().update();

  for (auto &[category, items] : itemsByCategory)
    std::erase_if(items, [](const Item &item) { return !item.active; });
}
