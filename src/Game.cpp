#include "Game.hpp"
#include <raylib.h>

void Game::run() {
  InitWindow(screenWidth, screenHeight, "PwatMan");

  Image pwatLeft = LoadImage("../assets/pwatleft.png");
  Image pwatRight = LoadImage("../assets/pwatright.png");
  Image pwatDown = LoadImage("../assets/pwatdown.png");
  Image pwatUp = LoadImage("../assets/pwatup.png");

  Texture2D textures[numPwats] = {0, 0, 0, 0, 0};
  textures[0] = LoadTextureFromImage(pwatLeft);
  textures[1] = LoadTextureFromImage(pwatRight);
  textures[2] = LoadTextureFromImage(pwatDown);
  textures[3] = LoadTextureFromImage(pwatUp);
  int currentTexture = 0;

  UnloadImage(pwatLeft);
  UnloadImage(pwatRight);
  UnloadImage(pwatDown);
  UnloadImage(pwatUp);

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

  for (int i = 0; i < numPwats; i++)
    UnloadTexture(textures[i]);

  CloseWindow();
}
