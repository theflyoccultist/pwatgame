#pragma once

#include <raylib.h>
#include <string>
#include <unordered_map>

class AssetSystem {
public:
  static AssetSystem &instance() {
    static AssetSystem instance;
    return instance;
  }

  AssetSystem(const AssetSystem &) = delete;
  AssetSystem &operator=(const AssetSystem &) = delete;

  Texture2D &loadTexture(const std::string &path, int w, int h);
  void drawTexture(const Texture2D *tex, int posX, int posY,
                   Color tint = WHITE);

  Texture2D &loadSprite(const std::string &path);
  void drawSprite(const Texture2D &sprite, float posX, float posY);

  void unloadAll();

private:
  AssetSystem() = default;
  ~AssetSystem() = default;

  std::unordered_map<std::string, Texture2D> textures;

  Rectangle frameRec;
  int currentFrame = 0;
  int framesCounter = 0;
  const int framesSpeed = 16;
};
