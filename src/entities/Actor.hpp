#pragma once

#include <raylib.h>

class Actor {
public:
  virtual ~Actor() = default;

  virtual void update(float dt, Vector2 playerPos) = 0;
  virtual void draw() const = 0;
};
