#include "Game.hpp"
#include "entities/EnemyManager.hpp"
#include "entities/PlayerManager.hpp"
#include "items/ItemsManager.hpp"
#include "projectiles/ProjectileManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  PlayerManager playerManager;
  PlayerState pwatState = playerManager.init();

  EnemyManager enemyManager;
  enemyManager.init();

  UIManager::loadUI();

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
      playerManager.reset(pwatState);

      ItemManager::instance().populateItems();
      enemyManager.clearAll();
      enemyManager.spawnEnemies(EnemyType::SWARMER, 5);
      enemyManager.spawnEnemies(EnemyType::SNIPER, 5);

      ProjectileManager::instance().clearAll();

      Game::currentState = GameState::Playing;
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD();

      playerManager.update(pwatState, deltaTime);

      ProjectileManager::instance().update(deltaTime);
      ProjectileManager::instance().draw();

      ItemManager::instance().updateItems(pwatState.position,
                                          PlayerState::playerSize);
      ItemManager::instance().drawItems(ItemCategory::Food);
      ItemManager::instance().drawItems(ItemCategory::Drink);

      auto bullets = ProjectileManager::instance().view();

      enemyManager.updateAll(deltaTime, pwatState, bullets);
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
