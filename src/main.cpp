#include "Game.hpp"
#include "RaylibApp.hpp"
#include <raylib.h>

int main() {
  RaylibApp app(800, 800, "PwatMan");
  Game game;
  game.run();
  return 0;
}
