#pragma once

#include "WallAxis.hpp"

struct WallSpec {
  MoveAxis axis = MoveAxis::Horizontal;
  float speed;
  float size;
  float warningTime;
  float activeTime;
  int contactDmg;
};
