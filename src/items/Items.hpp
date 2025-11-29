#include "ItemType.hpp"
#include <raylib.h>
#include <unordered_map>
#include <vector>

class Items {
public:
  Items();

  void draw(ItemCategory category, Vector2 position, size_t index);

private:
  std::unordered_map<ItemCategory, std::vector<Texture2D *>> allAssets;

  constexpr static int itemSize = 50;
};
