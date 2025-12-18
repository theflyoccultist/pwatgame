#pragma once

#include "../texture/AssetSystem.hpp"
#include "ProjectileType.hpp"

#include <unordered_map>

class ProjectileTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    int size = 50;

    projTextures[ProjectileType::GRENADE] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);

    projTextures[ProjectileType::HELLFIRE] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);

    projTextures[ProjectileType::LONGRANGE] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);

    projTextures[ProjectileType::ROCKET] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);

    projTextures[ProjectileType::SLOWCANNON] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);

    projTextures[ProjectileType::STRAIGHT] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);

    projTextures[ProjectileType::UZI] =
        &a.loadTexture("../assets/bullets/bullet_check.png", size, size);
  }

  static Texture2D *get(ProjectileType type) { return projTextures[type]; }

private:
  static inline std::unordered_map<ProjectileType, Texture2D *> projTextures;
};
