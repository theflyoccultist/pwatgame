#include "Game.hpp"

#include "GameState.hpp"
#include "levels/LevelLoader.hpp"
#include "levels/MusicScheduler.hpp"
#include "player/PlayerManager.hpp"
#include "sound/AudioSystem.hpp"
#include "ui/UIManager.hpp"
#include <raylib.h>

void Game::run() {
  WeaponDataBase wd(lua);
  EnemyDatabase ed(lua);
  MiniBossDatabase md(lua);

  ScheduleManager sm(world);
  SpawnScheduler ss(lua, world, sm);
  ItemScheduler is(lua, world, sm);

  LevelLoader levelLoader(wd, ed, md, sm, ss, is);
  levelLoader.initDatabase();

  PlayerManager playerManager(world);
  PlayerState pwatState = playerManager.init();

  MusicScheduler musicScheduler(world, sm);

  ss.initEnemies();

  UIManager::loadUI();

  auto &audio = AudioSystem::instance();
  audio.music->playTitleTrack();

  LevelID currentLevel = LevelID::Level1;

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
      levelLoader.load(currentLevel);
      playerManager.reset(pwatState);

      musicScheduler.scheduleMusic(currentLevel);

      Game::currentState = GameState::Playing;
      break;
    }

    case GameState::Playing: {
      UIManager::updatePlayerHUD();

      playerManager.update(pwatState, deltaTime);

      sm.updateScheduler(deltaTime);
      sm.updateProjectiles(deltaTime);
      is.updateItems(pwatState);
      ss.updateEnemies(deltaTime, pwatState);

      if (ss.updateMiniBoss(deltaTime, pwatState))
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

    case GameState::NextLevel:
      currentLevel++;
      Game::currentState = GameState::Restarting;
      break;
    }

    EndDrawing();
  }
}
