#pragma once

#include "Items.hpp"
#include <raylib.h>
#include <unordered_map>
#include <vector>

struct Item {
  ItemCategory category;
  int type;
  Vector2 position;
  Vector2 size = {50, 50};
  bool active = true;

  Item(ItemCategory c, int t, Vector2 pos)
      : category(c), type(t), position(pos) {}
};

struct itemTypes {
  int food;
  int drink;
};

class ItemManager {
public:
  void populateItems(ItemCategory cat, Vector2 pos);
  void drawItems(ItemCategory cat);
  void updateItems(const Vector2 &playerPos, float playerSize);
  void clearAll() { itemsByCategory.clear(); }

private:
  Items itemsObj;
  std::unordered_map<ItemCategory, std::vector<Item>> itemsByCategory;
};
