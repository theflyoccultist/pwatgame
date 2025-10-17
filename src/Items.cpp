#include "Items.hpp"
#include "texture/AssetSystem.hpp"
#include <array>

Items::Items() {
  const std::array<std::string, foodKinds> foods = {
      "../assets/items/buldak.png", "../assets/items/pho.png",
      "../assets/items/shinramyun.png", "../assets/items/tomyum.png",
      "../assets/items/yopokki.png"};

  for (size_t i = 0; i < foodKinds; ++i) {
    itemAssets[i] =
        &AssetSystem::instance().loadTexture(foods[i], foodSize, foodSize);
  }
}

void Items::draw(Vector2 position, int snacks) {
  AssetSystem::instance().drawTexture(itemAssets[snacks], position.x,
                                      position.y);
}
