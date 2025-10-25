#include "Projectile.hpp"
#include <memory>
#include <raylib.h>

class ProjectileFactory {
public:
  static std::unique_ptr<Projectile>
  createProjectile(ProjectileType type, Vector2 startPos, Vector2 dir);
};
