#include "Game.hpp"
#include "Player.hpp"
#include "items/ItemsManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat;
  static ItemManager itemManager;
  itemManager.populateItems();

  static UIManager uiManager;

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  AudioSystem::instance().playTitleTrack();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    AudioSystem::instance().updateMusic();

    switch (Game::currentState) {
    case GameState::MainMenu:
      uiManager.updateMainMenu();
      break;

    case GameState::Playing: {
      itemManager.drawItems(ItemCategory::Food);
      itemManager.drawItems(ItemCategory::Drink);
      pwat.draw(pwatPosition, currentTexture);
      auto state = pwat.playerMovements(currentTexture, pwatPosition);
      currentTexture = state.texture;
      pwatPosition = state.position;
      pwat.playerFootsteps();

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      break;
    }

    case GameState::Paused:
      uiManager.updatePauseMenu();
      break;

    case GameState::Options:
      uiManager.updateOptionsMenu();
      break;
    }

    EndDrawing();
  }
}
