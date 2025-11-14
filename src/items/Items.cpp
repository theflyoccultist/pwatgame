#include "Items.hpp"
#include "../texture/AssetSystem.hpp"
#include <array>

Items::Items() {
  auto &assets = AssetSystem::instance();

  const std::array<std::string, foodKinds> foods = {
      "../assets/items/buldak.png",     "../assets/items/pho.png",
      "../assets/items/shinramyun.png", "../assets/items/tomyum.png",
      "../assets/items/yopokki.png",
  };

  const std::array<std::string, drinkKinds> drinks = {
      "../assets/items/monster.png",   "../assets/items/soju.png",
      "../assets/items/calpis.png",    "../assets/items/bobatea.png",
      "../assets/items/icecoffee.png",
  };

  const std::array<std::string, weaponKinds> weapons = {
      "../assets/items/rocket.png",
  };

  for (const auto &f : foods)
    allAssets[ItemCategory::Food].push_back(
        &assets.loadTexture(f, itemSize, itemSize));

  for (const auto &d : drinks)
    allAssets[ItemCategory::Drink].push_back(
        &assets.loadTexture(d, itemSize, itemSize));

  for (const auto &w : weapons)
    allAssets[ItemCategory::Weapon].push_back(
        &assets.loadTexture(w, itemSize, itemSize));
}

void Items::draw(ItemCategory category, Vector2 position, size_t index) {
  auto &vec = allAssets[category];
  if (index >= vec.size())
    return;

  AssetSystem::instance().drawTexture(vec[index], (int)position.x,
                                      (int)position.y);
}
