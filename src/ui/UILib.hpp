#pragma once

class UILib {
public:
  void mainMenu();

  enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };
  PauseMenuOpts pauseMenu();
};
