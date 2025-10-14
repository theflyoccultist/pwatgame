#include <raylib.h>
#include <stdexcept>
#include <string>

class SoundEffects {
public:
  explicit SoundEffects(const std::string &path) {
    sfx = LoadSound(path.c_str());
    if (!IsSoundValid(sfx)) {
      throw std::runtime_error("Failed to load sfx: " + path);
    }
  }

  ~SoundEffects() { UnloadSound(sfx); }

  void play() { PlaySound(sfx); }
  void stop() { StopSound(sfx); }

private:
  Sound sfx;
};
