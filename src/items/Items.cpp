#include "Items.hpp"
#include "../texture/AssetSystem.hpp"
#include <array>

Items::Items() {
  auto &assets = AssetSystem::instance();

  const std::array<std::string, foodKinds> foods = {
      "../assets/items/buldak.png", "../assets/items/pho.png",
      "../assets/items/shinramyun.png", "../assets/items/tomyum.png",
      "../assets/items/yopokki.png"};

  const std::array<std::string, drinkKinds> drinks = {
      "../assets/items/monster.png", "../assets/items/soju.png",
      "../assets/items/calpis.png", "../assets/items/bobatea.png",
      "../assets/items/icecoffee.png"};

  for (const auto &path : foods)
    allAssets[ItemCategory::Food].push_back(
        &assets.loadTexture(path, foodSize, foodSize));

  for (const auto &path : drinks)
    allAssets[ItemCategory::Drink].push_back(
        &assets.loadTexture(path, foodSize, foodSize));
}

void Items::draw(ItemCategory category, Vector2 position, size_t index) {
  auto &vec = allAssets[category];
  if (index >= vec.size())
    return;

  AssetSystem::instance().drawTexture(vec[index], position.x, position.y);
}
