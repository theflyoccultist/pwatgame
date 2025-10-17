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
    addItem(ItemCategory::Food, 0, {100, 300});
    addItem(ItemCategory::Food, 1, {400, 600});
    addItem(ItemCategory::Food, 2, {300, 200});
    addItem(ItemCategory::Food, 3, {150, 80});
    addItem(ItemCategory::Food, 4, {90, 150});

    addItem(ItemCategory::PowerUp, 0, {400, 100});
    addItem(ItemCategory::PowerUp, 1, {100, 700});
    addItem(ItemCategory::PowerUp, 2, {700, 700});
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
