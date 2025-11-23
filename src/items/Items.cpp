#include "Items.hpp"
#include "../texture/AssetSystem.hpp"
#include <iostream>

Items::Items() {
  auto &assets = AssetSystem::instance();

  allAssets[ItemCategory::Food] = {
      &assets.loadTexture("../assets/items/buldak.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/pho.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/shinramyun.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/tomyum.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/yopokki.png", itemSize, itemSize),
  };

  allAssets[ItemCategory::Drink] = {
      &assets.loadTexture("../assets/items/monster.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/soju.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/calpis.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/bobatea.png", itemSize, itemSize),
      &assets.loadTexture("../assets/items/icecoffee.png", itemSize, itemSize),
  };

  allAssets[ItemCategory::Weapon] = {
      &assets.loadTexture("../assets/items/rocket.png", itemSize, itemSize),
  };
}

void Items::draw(ItemCategory category, Vector2 position, size_t index) {
  auto &vec = allAssets[category];
  if (index >= vec.size()) {
    std::cerr << "Items::draw - index not supported!\n";
    return;
  }

  AssetSystem::instance().drawTexture(vec[index], (int)position.x,
                                      (int)position.y);
}
