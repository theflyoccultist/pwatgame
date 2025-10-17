#pragma once

#include "Game.hpp"
#include <raylib.h>
#include <string>

class RaylibApp {
public:
  RaylibApp(int width, int height, const std::string &title) {
    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
    Game game;
    game.run();
  }

  ~RaylibApp() { CloseWindow(); }

  RaylibApp(const RaylibApp &) = delete;
  RaylibApp operator=(const RaylibApp &) = delete;
};
