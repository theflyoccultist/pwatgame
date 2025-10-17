#include <array>
#include <raylib.h>

class Items {
public:
  Items();
  void draw(Vector2 position, int snacks);

private:
  std::array<Texture2D *, 5> itemAssets;
};
