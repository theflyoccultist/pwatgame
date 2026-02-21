#pragma once

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

#if defined(__linux)
#include <linux/limits.h>
#include <unistd.h>

class Paths {
public:
  static fs::path getExecutablePath() {
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return fs::path(std::string(result, count));
  }

  static fs::path getbaseDir() {
    auto exePath = getExecutablePath();
    return exePath.parent_path();
  }

  static fs::path getAssetsPath() { return getbaseDir() / "assets"; }
  static fs::path getScriptsPath() { return getbaseDir() / "scripts"; }
};
#endif

#if defined(_WIN32)
#include <windows.h>

class Paths {
public:
  static fs::path getExecutablePath() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    return fs::path(buffer);
  }

  static fs::path getbaseDir() {
    auto exePath = getExecutablePath();
    return exePath.parent_path();
  }

  static fs::path getAssetsPath() { return getbaseDir() / "assets"; }
  static fs::path getScriptsPath() { return getbaseDir() / "scripts"; }
};
#endif
