#include "Game.hpp"
#include "entities/EnemyManager.hpp"
#include "entities/PlayerManager.hpp"
#include "items/ItemsManager.hpp"
#include "projectiles/ProjectileManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include "utils/Scheduler.hpp"
#include <raylib.h>

void Game::run() {
  PlayerManager playerManager;
  PlayerState pwatState = playerManager.init();

  EnemyManager enemyManager;
  enemyManager.init();
  Scheduler scheduler;

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
      enemyManager.clearAll();

      ProjectileManager::instance().clearAll();

      ItemManager::instance().populateItems(10, 10);

      enemyManager.spawnEnemies(EnemyType::SNIPER, 10);

      scheduler.schedule(10.0f, [&enemyManager] {
        enemyManager.spawnEnemies(EnemyType::SWARMER, 5);
      });

      scheduler.schedule(15.0f,
                         [] { ItemManager::instance().populateItems(2, 5); });

      scheduler.schedule(30.0f, [&enemyManager] {
        enemyManager.spawnEnemies(EnemyType::SWARMER, 25);
      });

      scheduler.schedule(50.0f, [&enemyManager] {
        enemyManager.spawnEnemies(EnemyType::SNIPER, 10);
      });

      scheduler.schedule(60.0f,
                         [] { ItemManager::instance().populateItems(7, 0); });

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

      scheduler.update(deltaTime);

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
