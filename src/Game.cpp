#include "Game.hpp"
#include "entities/EnemyManager.hpp"
#include "items/ItemsManager.hpp"
#include "projectiles/ProjectileManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  Player pwat;

  EnemyManager enemyManager;
  enemyManager.init();

  ProjectileManager projManager;
  projManager.init();

  UIManager::loadUI();

  int pwatTexture = 0;
  Vector2 pwatPosition = {static_cast<float>(screenWidth / 2.0),
                          static_cast<float>(screenHeight / 2.0)};
  Vector2 pwatDirection = {0.0f, 0.0f};

  PlayerState pwatState = {pwatTexture, pwatPosition, pwatDirection};

  AudioSystem::instance().playTitleTrack();

  while (!WindowShouldClose()) {
    deltaTime = GetFrameTime();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    AudioSystem::instance().updateMusic();

    switch (currentState) {
    case GameState::MainMenu:
      UIManager::updateMainMenu();
      break;

    case GameState::Restarting: {
      AudioSystem::instance().stopMusic();
      AudioSystem::instance().playLevelTrack();
      pwat.resetPlayerHealth();
      pwat.resetPlayerScore();

      ItemManager::instance().populateItems();
      enemyManager.clearAll();
      enemyManager.spawnEnemies(EnemyType::SWARMER, 5);
      enemyManager.spawnEnemies(EnemyType::SNIPER, 5);

      Game::currentState = GameState::Playing;
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD();
      auto state = pwat.playerMovements(pwatState, deltaTime);
      pwatState = state;

      pwat.draw(pwatState.position, pwatState.texture);
      pwat.playerFootsteps();

      ItemManager::instance().updateItems(pwatState.position);
      ItemManager::instance().drawItems(ItemCategory::Food);
      ItemManager::instance().drawItems(ItemCategory::Drink);

      projManager.update(deltaTime);
      projManager.draw();

      enemyManager.updateAll(deltaTime, pwatState.position,
                             projManager.getProjectilePositions());
      enemyManager.drawAll();

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
