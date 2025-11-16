#include "Game.hpp"
#include "entities/PlayerManager.hpp"
#include "levels/SpawnScheduler.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  PlayerManager playerManager(world);
  PlayerState pwatState = playerManager.init();

  SpawnScheduler spawner(world);
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

      spawner.resetScheduler();
      spawner.clearALlItems();
      spawner.clearAllEnemies();
      spawner.clearAllProjectiles();

      spawner.scheduleItems();
      spawner.schedulePowerUpItems();
      spawner.scheduleEnemies();
      spawner.scheduleMiniBoss();

      Game::currentState = GameState::Playing;
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD();

      playerManager.update(pwatState, deltaTime);

      spawner.updateScheduler(deltaTime);
      spawner.updateItems(pwatState);
      spawner.updateProjectiles(deltaTime);
      spawner.updateEnemies(deltaTime, pwatState);
      // spawner.updateMiniBoss(deltaTime);

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      if (pwatState.health <= 0)
        Game::currentState = GameState::Lost;

      break;
    }

    case GameState::Paused:
      UIManager::updatePauseMenu();
      break;

    case GameState::Options:
      UIManager::updateOptionsMenu();
      break;

    case GameState::Lost:
      UIManager::updateLostMenu();
      break;
    }

    EndDrawing();
  }
}
