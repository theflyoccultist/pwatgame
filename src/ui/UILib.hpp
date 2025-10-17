#pragma once

class UILib {
public:
  enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };
  static PauseMenuOpts pauseMenu();
  void optionsMenu();
  static void mainMenu();
};
