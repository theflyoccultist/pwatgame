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

  Texture2D &loadTexture(const std::string &path);
  void unloadAll();

private:
  AssetSystem() = default;
  ~AssetSystem() = default;

  std::unordered_map<std::string, Texture2D> textures;
};
