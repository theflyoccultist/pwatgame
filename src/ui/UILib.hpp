#pragma once

class UILib {
public:
  enum class PauseMenuOpts { Resume, Restart, Options, BackToMenu, Count };
  static PauseMenuOpts pauseMenu();

  enum class OptionMenuOpts { MusicVol, SfxVol, Count };
  static OptionMenuOpts optionsMenu(int musicVol, int sfxVol);

  static void mainMenu();

private:
  static constexpr int baseY = 210;
  static constexpr int spacing = 40;
};
