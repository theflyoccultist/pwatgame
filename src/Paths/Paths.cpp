#include <Paths/Paths.hpp>
#include <string>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#else
#include <linux/limits.h>
#include <unistd.h>
#endif

fs::path Paths::getExecutablePath() {
#ifdef _WIN32
  char buffer[MAX_PATH];
  GetModuleFileNameA(NULL, buffer, MAX_PATH);
  return fs::path(buffer);
#else
  char result[PATH_MAX];
  ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
  return fs::path(std::string(result, count));
#endif
}

fs::path Paths::getbaseDir() {
  auto exePath = getExecutablePath();
  return exePath.parent_path();
}
