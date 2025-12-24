#include "Game.hpp"
#include "GameModes.hpp"
#include "GameState.hpp"
#include "levels/LevelID.hpp"
#include "levels/LevelLoader.hpp"
#include "levels/MusicScheduler.hpp"
#include "levels/displayLevel.hpp"
#include "player/PlayerManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <iostream>
#include <raylib.h>

void Game::run() {
  WeaponDataBase wd(lua);
  EnemyDatabase ed(lua);
  MiniBossDatabase md(lua);

  ScheduleManager sm(world);
  SpawnScheduler ss(lua, world, sm);
  ItemScheduler is(lua, world, sm);
  ProjectileScheduler ps(world);

  lua.initLua();
  LevelLoader levelLoader(wd, ed, md, sm, ss, is, ps);
  levelLoader.initDatabase();
  levelLoader.loadEntityTextures();

  PlayerManager playerManager(world);
  playerManager.loadPlayerTextures();
  PlayerState pwatState = playerManager.initPlayerState();

  MusicScheduler musicScheduler(world, sm);

  UIManager::loadUITextures();

  auto &audio = AudioSystem::instance();
  audio.music->playTitleTrack();

  LevelID currentLevel = LevelID::Level1;
  GameModes gameMode = GameModes::Dealthless;

  while (!WindowShouldClose()) {
    deltaTime = GetFrameTime();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    audio.music->updateMusic();

    switch (currentState) {
    case GameState::MainMenu:
      UIManager::updateMainMenu(currentLevel, gameMode);
      break;

    case GameState::LevelSelection:
      UIManager::updateLevelSelection(currentLevel);
      break;

    case GameState::Restarting: {
      if (gameMode == GameModes::LevelSelection) {
        playerManager.resetStatus();
      }

      if (gameMode == GameModes::Dealthless &&
          currentLevel == LevelID::Level1) {
        playerManager.resetStatus();
      }

      playerManager.resetPosition(pwatState);

      levelLoader.load(currentLevel);
      musicScheduler.scheduleMusic(currentLevel);
      musicScheduler.scheduleBossMusic(currentLevel);
      std::cout << "Game::run() - Current level: " << currentLevel << "\n";
      Game::currentState = GameState::LevelIntro;
      break;
    }

    case GameState::LevelIntro: {
      UIManager::updateLevelIntro(displayCurrentLevel(currentLevel));
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD(displayCurrentLevel(currentLevel));
      UIManager::updateweaponHUD(pwatState.currWeapon);

      playerManager.update(pwatState, deltaTime);

      sm.updateScheduler(deltaTime);
      ps.updateProjectiles(deltaTime);
      is.updateItems(pwatState);
      ss.updateEnemies(deltaTime, pwatState);

      if (ss.updateMiniBoss(deltaTime, pwatState))
        Game::currentState = GameState::Won;

      if (IsKeyPressed(KEY_P))
        Game::currentState = GameState::Paused;

      if (pwatState.playerHealth <= 0)
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
      UIManager::updateLostMenu(currentLevel, gameMode);
      break;

    case GameState::Won:
      UIManager::winningMenu(displayCurrentLevel(currentLevel));
      break;

    case GameState::NextLevel:
      currentLevel++;
      Game::currentState = GameState::Restarting;
      break;

    case GameState::ShowCredits:
      UIManager::updateCredits();
      break;
    }

    EndDrawing();
  }
}
