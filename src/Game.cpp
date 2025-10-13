#include "Game.hpp"
#include "Player.hpp"
#include <raylib.h>

void Game::run() {

  Player pwat({
      "../assets/pwatleft.png",
      "../assets/pwatright.png",
      "../assets/pwatdown.png",
      "../assets/pwatup.png",
  });

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyDown(KEY_LEFT)) {
      currentTexture = 0;
      pwatPosition.x -= 2.0f;
    }
    if (IsKeyDown(KEY_RIGHT)) {
      currentTexture = 1;
      pwatPosition.x += 2.0f;
    }
    if (IsKeyDown(KEY_DOWN)) {
      currentTexture = 2;
      pwatPosition.y += 2.0f;
    }
    if (IsKeyDown(KEY_UP)) {
      currentTexture = 3;
      pwatPosition.y -= 2.0f;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("PwatPwat - The Game", 275, 20, 20, DARKPURPLE);
    pwat.draw(pwatPosition, currentTexture);
    EndDrawing();
  }
}
