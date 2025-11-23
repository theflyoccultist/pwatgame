#pragma once

#include <functional>
#include <vector>

class Scheduler {
public:
  void init() {
    tasks.clear();
    currentTime = 0.0;
  }

  void schedule(double delay, std::function<void()> action) {
    tasks.push_back({currentTime + delay, std::move(action), false});
  }

  void update(float deltaTime) {
    currentTime += deltaTime;
    for (auto &task : tasks) {
      if (!task.done && currentTime >= task.triggerTime) {
        task.action();
        task.done = true;
      }
    }
  }

private:
  struct Task {
    double triggerTime;
    std::function<void()> action;
    bool done;
  };

  double currentTime = 0.0;
  std::vector<Task> tasks;
};
