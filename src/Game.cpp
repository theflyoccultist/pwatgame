#include "Game.hpp"
#include "levels/ItemScheduler.hpp"
#include "levels/ScheduleManager.hpp"
#include "levels/SpawnScheduler.hpp"
#include "player/PlayerManager.hpp"
#include "projectiles/WeaponDatabase.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  PlayerManager playerManager(world);
  PlayerState pwatState = playerManager.init();

  ScheduleManager sm(lua, world);
  SpawnScheduler spawnScheduler(lua, world, sm);
  ItemScheduler itemScheduler(lua, world, sm);
  spawnScheduler.initEnemies();

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

      sm.resetScheduler();
      itemScheduler.clearAllItems();
      spawnScheduler.clearAllEnemies();
      sm.clearAllProjectiles();

      sm.scheduleMusic();

      WeaponDataBase::loadFromLua(lua, "../scripts/weaponData.lua");

      itemScheduler.scheduleItems("../scripts/lvl1Items.lua");
      spawnScheduler.scheduleEnemies("../scripts/lvl1Enemies.lua");
      spawnScheduler.scheduleMiniBoss();

      Game::currentState = GameState::Playing;
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD();

      playerManager.update(pwatState, deltaTime);

      sm.updateScheduler(deltaTime);
      itemScheduler.updateItems(pwatState);
      sm.updateProjectiles(deltaTime);
      spawnScheduler.updateEnemies(deltaTime, pwatState);

      if (spawnScheduler.updateMiniBoss(deltaTime, pwatState))
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
