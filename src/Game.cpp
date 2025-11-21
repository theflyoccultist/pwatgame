#include "Game.hpp"
#include "player/PlayerManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  PlayerManager playerManager(world);
  PlayerState pwatState = playerManager.init();

  SpawnScheduler spawner(world, lua);
  spawner.initEnemies();

  UIManager::loadUI();

  auto &audio = AudioSystem::instance();
  audio.music->playTitleTrack();

  while (!WindowShouldClose()) {
    deltaTime = GetFrameTime();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    audio.music->updateMusic();

    switch (currentState) {
    case GameState::MainMenu:
      UIManager::updateMainMenu();
      break;

    case GameState::Restarting: {
      playerManager.reset(pwatState);

      spawner.resetScheduler();
      spawner.clearAllItems();
      spawner.clearAllEnemies();
      spawner.clearAllProjectiles();

      spawner.scheduleMusic();
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

      if (spawner.updateMiniBoss(deltaTime, pwatState))
        Game::currentState = GameState::Won;

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

    case GameState::Won:
      UIManager::winningMenu();
      break;
    }

    EndDrawing();
  }
}
