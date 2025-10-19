#pragma once

#include "Items.hpp"
#include <unordered_map>
#include <vector>

struct Item {
  ItemCategory category;
  int type;
  Vector2 position;

  Item(ItemCategory c, int t, Vector2 pos)
      : category(c), type(t), position(pos) {}
};

class ItemManager {
public:
  void addItem(ItemCategory cat, int type, Vector2 pos) {
    itemsByCategory[cat].emplace_back(cat, type, pos);
  }

  void populateItems() {
    std::unordered_map<ItemCategory, std::vector<Vector2>> itemPositions = {
        {ItemCategory::Food,
         {
             {100, 300},
             {400, 600},
             {300, 200},
             {150, 80},
             {90, 150},
         }},

        {ItemCategory::Drink,
         {
             {400, 100},
             {350, 150},
             {700, 700},
             {150, 550},
             {340, 600},
         }}};

    for (auto &[category, positions] : itemPositions) {
      for (size_t i = 0; i < positions.size(); ++i) {
        addItem(category, static_cast<int>(i), positions[i]);
      }
    }
  }

  void drawItems(ItemCategory cat) {
    auto it = itemsByCategory.find(cat);
    if (it == itemsByCategory.end())
      return;

    for (auto &item : it->second)
      itemsObj.draw(item.category, item.position, item.type);
  }

private:
  std::unordered_map<ItemCategory, std::vector<Item>> itemsByCategory;
  Items itemsObj;
};
