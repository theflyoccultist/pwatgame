#include <array>
#include <cstddef>
#include <raylib.h>
#include <string>

struct PlayerState {
  int texture;
  Vector2 position;
};

class Player {
public:
  const static std::size_t numPwats = 4;

  Player(std::array<std::string, numPwats> paths) {
    for (size_t i = 0; i < paths.size(); ++i) {
      Image img = LoadImage(paths[i].c_str());
      textures[i] = LoadTextureFromImage(img);
      UnloadImage(img);
    }
  }

  ~Player() {
    for (auto &tex : textures)
      UnloadTexture(tex);
  }

  PlayerState playerMovements(int current, Vector2 playerPosition);

  void draw(Vector2 position, int direction) {
    DrawTexture(textures[direction], position.x, position.y, WHITE);
  }

private:
  std::array<Texture2D, numPwats> textures;
};
