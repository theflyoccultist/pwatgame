#pragma once

class UILib {
public:
  enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };

  static PauseMenuOpts pauseMenu();
  static void optionsMenu();
  static void mainMenu();

private:
  static constexpr int baseY = 210;
  static constexpr int spacing = 40;
};
