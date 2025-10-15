#include "Game.hpp"
#include "RaylibApp.hpp"

int main() {
  RaylibApp app(800, 800, "PwatMan");
  Game game;
  game.run();
  return 0;
}
