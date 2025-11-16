#pragma once

#include <array>
#include <raylib.h>

class Actor {
public:
  virtual ~Actor() = default;

  virtual void update(float dt, Vector2 playerPos) = 0;
  virtual void draw() const = 0;

protected:
  const Texture2D *
  chooseTexture(float ratio, const std::array<Texture2D *, 3> &textures) const {
    if (textures[0] == nullptr)
      return nullptr;
    if (ratio > 0.66f)
      return textures[0];
    if (ratio > 0.33f)
      return textures[1];
    return textures[2];
  }

  const Color healthbarColor(float ratio) const {
    if (ratio > 0.66f)
      return GREEN;
    if (ratio > 0.33f)
      return YELLOW;
    return RED;
  }
};
