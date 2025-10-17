#include "Items.hpp"
#include <vector>

class ItemManager {
public:
  void addItem(Vector2 pos, int type) { items.push_back({pos, type}); }

  void addFoodItems() {
    addItem({100, 300}, 0);
    addItem({400, 600}, 1);
    addItem({300, 200}, 2);
    addItem({150, 80}, 3);
    addItem({90, 150}, 4);
  }

  void drawAll() {
    for (auto &item : items)
      itemsObj.draw(item.position, item.type);
  }

private:
  struct Item {
    Vector2 position;
    int type;
  };

  std::vector<Item> items;
  Items itemsObj;
};
