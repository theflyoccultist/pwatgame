#include <cstdint>
#include <raylib.h>
#include <unordered_map>
#include <vector>

enum class ItemCategory : uint8_t { Food, Drink, Weapon };

class Items {
public:
  Items();

  void draw(ItemCategory category, Vector2 position, size_t index);

private:
  std::unordered_map<ItemCategory, std::vector<Texture2D *>> allAssets;

  constexpr static int itemSize = 50;
  constexpr static std::uint8_t foodKinds = 5;
  constexpr static std::uint8_t drinkKinds = 5;
  constexpr static std::uint8_t weaponKinds = 1;
};
