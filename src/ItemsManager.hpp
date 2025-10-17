#include "Items.hpp"
#include <vector>

class ItemManager {
public:
  void addItem(Vector2 pos, int type) { items.push_back({pos, type}); }

  void drawAll() {
    for (auto &item : items)
      itemsObj.draw(item.position, item.snacks);
  }

private:
  struct Item {
    Vector2 position;
    int snacks;
  };

  std::vector<Item> items;
  Items itemsObj;
};
