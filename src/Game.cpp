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

  int pwatTexture = 0;
  const float pwatCenter = static_cast<float>(pwat.pwatSize / 2.0);
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  Vector2 pwatDirection = {0.0f, 0.0f};

  PlayerState pwatState = {pwatTexture, pwatPosition, pwatDirection};

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
      itemManager.updateItems(pwatState.position);

      UIManager::updatePlayerHUD();

      auto state = pwat.playerMovements(pwatState);
      pwatState = state;
      pwat.draw(pwatState.position, pwatState.texture);

      PlayerProjectiles::update({pwatState.position.x + pwatCenter,
                                 pwatState.position.y + pwatCenter},
                                pwatState.direction, deltaTime);
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
