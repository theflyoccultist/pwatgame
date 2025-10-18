#include <raylib.h>
#include <unordered_map>
#include <vector>

enum class ItemCategory { Food, Drink };

class Items {
public:
  Items();

  void draw(ItemCategory category, Vector2 position, size_t index);

private:
  std::unordered_map<ItemCategory, std::vector<Texture2D *>> allAssets;

  constexpr static int foodSize = 50;
  constexpr static std::size_t foodKinds = 5;
  constexpr static std::size_t drinkKinds = 5;
};
