#include <raylib.h>
#include <stdexcept>
#include <texture/AssetSystem.hpp>

Texture2D &AssetSystem::loadTexture(const std::string &path) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;

  Image img = LoadImage(path.c_str());
  if (!IsImageValid(img))
    throw std::runtime_error("Failed to load image: " + path);

  Texture2D tex = LoadTextureFromImage(img);
  UnloadImage(img);

  auto [inserted, _] = textures.emplace(path, tex);
  return inserted->second;
}

void AssetSystem::drawTexture(const Texture2D *tex, float posX, float posY,
                              float size, float rotation, Color tint) {
  if (!tex)
    return;

  float scale = size / (float)tex->width;

  DrawTextureEx(*tex, {posX, posY}, rotation, scale, tint);
}

Texture2D &AssetSystem::loadSprite(const std::string &path) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;

  Image tempImg = LoadImage(path.c_str());
  if (!IsImageValid(tempImg))
    throw std::runtime_error("Failed to load sprite: " + path);

  ImageResize(&tempImg, (int)tempImg.width, (int)tempImg.height);
  Texture2D sprite = LoadTextureFromImage(tempImg);

  UnloadImage(tempImg);

  auto [inserted, _] = textures.emplace(path, sprite);
  return inserted->second;
}

void AssetSystem::drawSprite(const Texture2D &sprite, Vector2 position,
                             int frames) {
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    frameRec = {(float)currentFrame * (float)sprite.width / (float)frames, 0.0f,
                (float)sprite.width / (float)frames, (float)sprite.height};
  }

  DrawTextureRec(sprite, frameRec, position, WHITE);
}

void AssetSystem::unloadAll() {
  for (auto &[path, tex] : textures)
    UnloadTexture(tex);
  textures.clear();
}
