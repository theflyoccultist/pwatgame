#pragma once

#include <items/Item.hpp>
#include <memory>
#include <raylib.h>
#include <utility>
#include <vector>

class ItemManager {
public:
  ItemManager() = default;

  ItemManager(const ItemManager &) = delete;
  ItemManager &operator=(const ItemManager &) = delete;

  template <typename T, typename... Args> T &spawnItem(Args &&...args);

  void init();
  void updateAll(const PlayerState &player);
  void drawAll();
  void clearAll();

private:
  static constexpr int ITEM_POOL = 150;
  std::vector<std::unique_ptr<Item>> items;
};

// Example usage :
// auto &food = spawnItem<ItemFood>(FoodType::Apple);
// food.reset(pos, spec);

template <typename T, typename... Args>
T &ItemManager::spawnItem(Args &&...args) {
  items.push_back(std::make_unique<T>(std::forward<Args>(args)...));
  return *static_cast<T *>(items.back().get());
}
