#include <random>

class Random {
public:
  static int rangeInt(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    return dist(getEngine());
  }

  static float rangeFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(getEngine());
  }

  static bool chance(float probability) {
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    return dist(getEngine()) < probability;
  }

private:
  static std::mt19937 &getEngine() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return gen;
  }
};
