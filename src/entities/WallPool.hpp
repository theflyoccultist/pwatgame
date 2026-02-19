#include <entities/Wall_Immobile.hpp>
#include <entities/Wall_Moving.hpp>
#include <raylib.h>

class WallPool {
private:
  static constexpr int WALL_POOL = 75;
  static inline std::array<ImmobileWall, WALL_POOL> wallPool;
  static inline std::array<MovingWall, WALL_POOL> wallmovePool;

public:
  template <typename T> static std::array<T, WALL_POOL> &poolForType();

  template <typename T>
  static T *getFreeWall(const Vector2 &pos, const WallSpec &spec) {
    auto &pool = poolForType<T>();
    for (auto &p : pool) {
      if (!p.isActive()) {
        p.reset(pos, spec);
        p.setTexture();
        return &p;
      }
    }
    return nullptr;
  }
};

template <>
inline std::array<ImmobileWall, WallPool::WALL_POOL> &
WallPool::poolForType<ImmobileWall>() {
  return wallPool;
}

template <>
inline std::array<MovingWall, WallPool::WALL_POOL> &
WallPool::poolForType<MovingWall>() {
  return wallmovePool;
}
