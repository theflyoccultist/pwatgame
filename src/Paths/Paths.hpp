#pragma once

#include <filesystem>

namespace fs = std::filesystem;

class Paths {
public:
  static fs::path getExecutablePath();
  static fs::path getbaseDir();

  static fs::path getAssetsPath() { return getbaseDir() / "assets"; }
  static fs::path getScriptsPath() { return getbaseDir() / "scripts"; }
};
