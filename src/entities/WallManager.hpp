#pragma once

#include <entities/WallFactory.hpp>
#include <entities/WallSpec.hpp>
#include <entities/WallType.hpp>
#include <player/PlayerState.hpp>
#include <projectiles/Projectile.hpp>

#include <raylib.h>

class WallManager {
public:
  WallManager() = default;

  WallManager(const WallManager &) = delete;
  WallManager &operator=(const WallManager &) = delete;

  void init();
  void spawnWall(WallType type, const Vector2 &pos, const WallSpec &spec);

  void updateAll(float delta, const PlayerState &player,
                 std::span<Projectile *const> bullets);
  void drawAll();
  void clearAll();

  void resetTimer() { wallTimer = 0.0f; }

private:
  WallFactory factory;
  float wallTimer = 0.0f;

  static constexpr int WALL_POOL = 75;
  std::array<Wall *, WALL_POOL> walls{};
};
