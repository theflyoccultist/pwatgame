#include <raylib.h>
#include <string>

class TextureWrapper {
public:
  TextureWrapper(const std::string &path) {
    texture = LoadTexture(path.c_str());
  }

  ~TextureWrapper() { UnloadTexture(texture); }

  Texture2D &get() { return texture; }

private:
  Texture2D texture;
};
