#pragma once

#include <filesystem>

namespace fs = std::filesystem;

#if defined(_WIN32)
#include <windows.h>
#else
#include <linux/limits.h>
#include <unistd.h>
#endif

class Paths {
public:
  static fs::path getExecutablePath();
  static fs::path getbaseDir();

  static fs::path getAssetsPath() { return getbaseDir() / "assets"; }
  static fs::path getScriptsPath() { return getbaseDir() / "scripts"; }
};
