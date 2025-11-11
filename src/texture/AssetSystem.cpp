#include "AssetSystem.hpp"
#include <raylib.h>
#include <stdexcept>

Texture2D &AssetSystem::loadTexture(const std::string &path, int w, int h) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;

  Image img = LoadImage(path.c_str());
  if (!IsImageValid(img))
    throw std::runtime_error("Failed to load image: " + path);

  ImageResize(&img, w, h);
  Texture2D tex = LoadTextureFromImage(img);
  UnloadImage(img);

  auto [inserted, _] = textures.emplace(path, tex);
  return inserted->second;
}

void AssetSystem::drawTexture(const Texture2D *tex, int posX, int posY,
                              Color tint) {
  if (!tex)
    return;
  DrawTexture(*tex, posX, posY, tint);
}

Texture2D &AssetSystem::loadSprite(const std::string &path) {
  auto it = textures.find(path);
  if (it != textures.end())
    return it->second;

  Image tempImg = LoadImage(path.c_str());
  if (!IsImageValid(tempImg))
    throw std::runtime_error("Failed to load sprite: " + path);

  ImageResize(&tempImg, tempImg.width * 1.5, tempImg.height * 1.5);
  Texture2D sprite = LoadTextureFromImage(tempImg);

  UnloadImage(tempImg);
  frameRec = {0.0f, 0.0f, (float)sprite.width / 14, (float)sprite.height};

  auto [inserted, _] = textures.emplace(path, sprite);
  return inserted->second;
}

void AssetSystem::drawSprite(const Texture2D &sprite, float posX, float posY) {
  framesCounter++;

  if (framesCounter >= (60 / framesSpeed)) {
    framesCounter = 0;
    currentFrame++;

    frameRec.x = (float)currentFrame * (float)sprite.width / 14;
  }

  DrawTextureRec(sprite, frameRec, {posX, posY}, WHITE);
}

void AssetSystem::unloadAll() {
  for (auto &[path, tex] : textures)
    UnloadTexture(tex);
  textures.clear();
}
