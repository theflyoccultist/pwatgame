#include "Game.hpp"
#include "entities/PlayerManager.hpp"
#include "levels/SpawnScheduler.hpp"
#include "projectiles/ProjectileManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  PlayerManager playerManager;
  PlayerState pwatState = playerManager.init();

  SpawnScheduler spawner;
  spawner.init();

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
      spawner.clearAllEnemies();

      ProjectileManager::instance().clearAll();

      spawner.scheduleItems();
      spawner.scheduleEnemies();

      Game::currentState = GameState::Playing;
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD();

      playerManager.update(pwatState, deltaTime);

      ProjectileManager::instance().update(deltaTime);
      ProjectileManager::instance().draw();

      auto bullets = ProjectileManager::instance().view();

      spawner.updateScheduler(deltaTime);
      spawner.updateItems(pwatState);
      spawner.updateEnemies(deltaTime, pwatState, bullets);

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
