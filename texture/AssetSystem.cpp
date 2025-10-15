#include "AssetSystem.hpp"
#include <stdexcept>

Texture2D &AssetSystem::loadTexture(const std::string &path) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;

  Image img = LoadImage(path.c_str());
  if (!IsImageValid(img))
    throw std::runtime_error("Failed to load image: " + path);

  ImageResize(&img, 70, 70);
  Texture2D tex = LoadTextureFromImage(img);
  UnloadImage(img);

  auto [inserted, _] = textures.emplace(path, tex);
  return inserted->second;
}

void AssetSystem::unloadAll() {
  for (auto &[path, tex] : textures)
    UnloadTexture(tex);
  textures.clear();
}
