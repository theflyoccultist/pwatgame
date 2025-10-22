#pragma once

#include "../Player.hpp"
#include "../items/FeedbackSystem.hpp"
#include "../projectiles/PlayerProjectiles.hpp"
#include "../utils/Random.hpp"
#include "Items.hpp"
#include <raylib.h>
#include <unordered_map>
#include <vector>

struct Item {
  ItemCategory category;
  int type;
  Vector2 position;
  Vector2 size = {55, 55};
  bool active = true;

  Item(ItemCategory c, int t, Vector2 pos)
      : category(c), type(t), position(pos) {}
};

class ItemManager {
public:
  static ItemManager &instance() {
    static ItemManager instance;
    return instance;
  }

  void addItem(ItemCategory cat, int type, Vector2 pos) {
    itemsByCategory[cat].emplace_back(cat, type, pos);
  }

  void populateItems() {
    itemsByCategory.clear();

    std::unordered_map<ItemCategory, std::vector<Vector2>> itemPositions = {
        {ItemCategory::Food, {}}, {ItemCategory::Drink, {}}};

    for (auto &[category, positions] : itemPositions) {
      for (size_t i = 0; i < 4; ++i) {
        addItem(category, static_cast<int>(i),
                {Random::rangeFloat(0.0f, 730.0f),
                 Random::rangeFloat(0.0f, 730.0f)});
      }
    }
  }

  void drawItems(ItemCategory cat) {
    auto it = itemsByCategory.find(cat);
    if (it == itemsByCategory.end())
      return;

    for (auto &item : it->second)
      itemsObj.draw(item.category, item.position, item.type);

    FeedbackSystem::instance().draw();
  }

  void updateItems(Vector2 playerPos) {
    for (auto &[category, items] : itemsByCategory) {
      for (auto &item : items) {
        if (item.active && checkPickup(playerPos, item)) {
          item.active = false;

          switch (item.category) {
          case ItemCategory::Food:
            PlayerProjectiles::addAmmo(20);
            FeedbackSystem::instance().addFeedback("+20 AMMO", playerPos);
            break;

          case ItemCategory::Drink:
            Player::changePlayerHealth(20);
            FeedbackSystem::instance().addFeedback("+20 HP", playerPos);
            break;
          }
        }
      }
    }

    FeedbackSystem::instance().update();

    for (auto &[category, items] : itemsByCategory)
      std::erase_if(items, [](const Item &item) { return !item.active; });
  }

private:
  std::unordered_map<ItemCategory, std::vector<Item>> itemsByCategory;
  Items itemsObj;

  bool checkPickup(Vector2 playerPos, const Item &item) {

    Rectangle playerRect = {playerPos.x, playerPos.y, PlayerState::playerSize,
                            PlayerState::playerSize};
    Rectangle itemRect = {item.position.x, item.position.y, item.size.x,
                          item.size.y};

    return CheckCollisionRecs(playerRect, itemRect);
  }
};
