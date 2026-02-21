#include <Paths/Paths.hpp>
#include <string>

fs::path Paths::getExecutablePath() {
#if defined(_WIN32)
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
