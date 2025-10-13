#include "Game.hpp"
#include <array>
#include <cstddef>
#include <raylib.h>

void Game::run() {
  InitWindow(screenWidth, screenHeight, "PwatMan");

  std::array<Image, 4> pwatImages = {
      LoadImage("../assets/pwatleft.png"),
      LoadImage("../assets/pwatright.png"),
      LoadImage("../assets/pwatdown.png"),
      LoadImage("../assets/pwatup.png"),
  };

  std::array<Texture2D, 4> textures;
  for (size_t i = 0; i < pwatImages.size(); ++i) {
    textures[i] = LoadTextureFromImage(pwatImages[i]);
    UnloadImage(pwatImages[i]);
  }

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
    DrawTexture(textures[currentTexture], pwatPosition.x, pwatPosition.y,
                WHITE);

    EndDrawing();
  }

  for (auto &tex : textures)
    UnloadTexture(tex);

  CloseWindow();
}
