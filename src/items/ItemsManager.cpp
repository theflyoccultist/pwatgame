#include "ItemsManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../player/Player.hpp"
#include "../projectiles/WeaponDatabase.hpp"
#include "../sound/AudioSystem.hpp"
#include "../utils/Random.hpp"
#include "FeedbackSystem.hpp"
#include <array>
#include <iostream>
#include <raylib.h>

void ItemManager::populateItems(ItemCategory cat, Vector2 pos) {
  itemsByCategory[cat].emplace_back(cat, Random::rangeInt(0, 4), pos);
}

void ItemManager::drawItems(ItemCategory cat) {
  auto it = itemsByCategory.find(cat);
  if (it == itemsByCategory.end())
    return;

  for (auto &item : it->second)
    itemsObj.draw(item.category, item.position, item.type);

  FeedbackSystem::instance().draw();
}

const std::array<ProjectileType, 3> weaponForPlayer = {
    ProjectileType::STRAIGHT,
    ProjectileType::ROCKET,
    ProjectileType::UZI,
};

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
          int selectedWeapon = Random::rangeInt(0, weaponForPlayer.size() - 1);
          auto newType = weaponForPlayer.at(selectedWeapon);

          std::cout << "Picked projectile type: " << newType << '\n';
          PlayerState::currWeapon = newType;
          PlayerState::currentWeaponSpec = WeaponDataBase::get(newType);

          FeedbackSystem::instance().addFeedback(toString(newType), playerPos);
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
