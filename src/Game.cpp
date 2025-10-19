#include "Game.hpp"
#include "Player.hpp"
#include "items/ItemsManager.hpp"
#include "projectiles/PlayerProjectiles.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"

void Game::run() {
  Player pwat;
  static ItemManager itemManager;
  itemManager.populateItems();

  UIManager::loadUI();

  PlayerProjectiles::init();

  int currentTexture = 0;
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};

  AudioSystem::instance().playTitleTrack();

  while (!WindowShouldClose()) {
    Game::deltaTime = GetFrameTime();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    AudioSystem::instance().updateMusic();

    switch (Game::currentState) {
    case GameState::MainMenu:
      UIManager::updateMainMenu();
      break;

    case GameState::Playing: {
      itemManager.drawItems(ItemCategory::Food);
      itemManager.drawItems(ItemCategory::Drink);
      pwat.draw(pwatPosition, currentTexture);
      auto state = pwat.playerMovements(currentTexture, pwatPosition);
      currentTexture = state.texture;
      pwatPosition = state.position;

      PlayerProjectiles::update(pwatPosition, deltaTime);
      PlayerProjectiles::draw();

      pwat.playerFootsteps();

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      break;
    }

    case GameState::Paused:
      UIManager::updatePauseMenu();
      break;

    case GameState::Options:
      UIManager::updateOptionsMenu();
      break;
    }

    EndDrawing();
  }
}
