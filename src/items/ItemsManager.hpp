#pragma once

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
  void addItem(ItemCategory cat, int type, Vector2 pos);
  void populateItems(int food, int drink, int weapon);
  void drawItems(ItemCategory cat);
  void updateItems(const Vector2 &playerPos, float playerSize);
  void clearAll() { itemsByCategory.clear(); }

private:
  Items itemsObj;
  std::unordered_map<ItemCategory, std::vector<Item>> itemsByCategory;
};
