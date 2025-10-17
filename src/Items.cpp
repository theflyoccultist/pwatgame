#include "Items.hpp"
#include "texture/AssetSystem.hpp"
#include <array>

Items::Items() {
  const std::array<std::string, 5> paths = {
      "../assets/items/buldak.png", "../assets/items/pho.png",
      "../assets/items/shinramyun.png", "../assets/items/tomyum.png",
      "../assets/items/yopokki.png"};

  for (size_t i = 0; i < 5; ++i) {
    itemAssets[i] = &AssetSystem::instance().loadTexture(paths[i], 70, 70);
  }
}

void Items::draw(Vector2 position, int snacks) {
  AssetSystem::instance().drawTexture(itemAssets[snacks], position.x,
                                      position.y);
}
