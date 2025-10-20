#include "Game.hpp"
#include "entities/EntityManager.hpp"
#include "items/ItemsManager.hpp"
#include "projectiles/PlayerProjectiles.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat;

  EntityManager entityManager;

  UIManager::loadUI();

  PlayerProjectiles::init();

  int pwatTexture = 0;
  const float pwatCenter = static_cast<float>(PlayerState::playerSize / 2.0);
  Vector2 pwatPosition = {(float)screenWidth / 2, (float)screenHeight / 2};
  Vector2 pwatDirection = {0.0f, 0.0f};

  PlayerState pwatState = {pwatTexture, pwatPosition, pwatDirection};

  AudioSystem::instance().playTitleTrack();

  ItemManager::instance().populateItems();

  entityManager.spawnEnemies();

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
      UIManager::updatePlayerHUD();

      auto state = pwat.playerMovements(pwatState);
      pwatState = state;

      pwat.draw(pwatState.position, pwatState.texture);
      pwat.playerFootsteps();

      ItemManager::instance().updateItems(pwatState.position);
      ItemManager::instance().drawItems(ItemCategory::Food);
      ItemManager::instance().drawItems(ItemCategory::Drink);

      PlayerProjectiles::update({pwatState.position.x + pwatCenter,
                                 pwatState.position.y + pwatCenter},
                                pwatState.direction, deltaTime);
      PlayerProjectiles::draw();

      entityManager.updateEnemies(PlayerProjectiles::getProjectilePositions(),
                                  pwatState.position);
      entityManager.drawEnemies();

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      break;
    }

    case GameState::Paused:
      UIManager::updatePauseMenu();
      break;

    case GameState::Restarting:
      AudioSystem::instance().stopMusic();
      AudioSystem::instance().playLevelTrack();
      PlayerProjectiles::init();
      pwat.resetPlayerHealth();

      ItemManager::instance().populateItems();
      entityManager.spawnEnemies();
      entityManager.drawEnemies();

      Game::currentState = GameState::Playing;
      break;

    case GameState::Options:
      UIManager::updateOptionsMenu();
      break;
    }

    EndDrawing();
  }
}
