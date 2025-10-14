#include <array>
#include <cstddef>
#include <raylib.h>
#include <stdexcept>
#include <string>

class SoundEffects {
public:
  static constexpr std::size_t numSounds = 5;

  explicit SoundEffects(const std::string &path) {
    if (nextSound < numSounds) {
      sfx[nextSound] = LoadSound(path.c_str());
      if (!IsSoundValid(sfx[nextSound])) {
        throw std::runtime_error("Failed to load sfx: " + path);
      }
      nextSound++;
    } else {
      throw std::runtime_error("SoundEffects capacity exceeded.");
    }
  }

  ~SoundEffects() {
    for (auto &s : sfx) {
      if (IsSoundValid(s))
        UnloadSound(s);
    }
  }

  void playSound(std::size_t index) {
    if (index < nextSound && IsSoundValid(sfx[index]))
      PlaySound(sfx[index]);
  }

  void stopAll() {
    for (auto &s : sfx)
      StopSound(s);
  }

private:
  static std::size_t nextSound;
  std::array<Sound, numSounds> sfx{};
};
