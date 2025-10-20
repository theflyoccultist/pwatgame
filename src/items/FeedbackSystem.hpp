#include "../Game.hpp"
#include <algorithm>
#include <raylib.h>
#include <string>
#include <vector>

class FeedbackSystem {
private:
  struct FloatingText {
    std::string text;
    Vector2 position;
    float lifetime;
    float alpha;
  };

  std::vector<FloatingText> feedbacks;

public:
  static FeedbackSystem &instance() {
    static FeedbackSystem instance;
    return instance;
  }

  void addFeedback(const std::string &text, Vector2 playerPos) {
    feedbacks.push_back({text, playerPos, 1.0f, 255});
  }

  void update() {
    for (auto &fb : feedbacks) {
      fb.position.y -= 20 * Game::deltaTime;
      fb.lifetime -= Game::deltaTime;
      fb.alpha = std::max(0.0f, fb.alpha - 255 * Game::deltaTime);
    }

    std::erase_if(feedbacks, [](auto &f) { return f.lifetime <= 0; });
  }

  void draw() const {
    for (auto &fb : feedbacks) {
      DrawText(fb.text.c_str(), fb.position.x, fb.position.y, 16,
               Fade(BLUE, fb.alpha / 255.0f));
    }
  }
};
