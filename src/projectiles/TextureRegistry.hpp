#pragma once

#include "../texture/AssetSystem.hpp"
#include "ProjectileType.hpp"

#include <unordered_map>

class ProjectileTextures {
public:
  static void loadTextures() {
    auto &a = AssetSystem::instance();

    projTextures[ProjectileType::GRENADE] =
        &a.loadTexture("../assets/bullets/bullet_check.png");

    projTextures[ProjectileType::HELLFIRE] =
        &a.loadTexture("../assets/bullets/bullet_check.png");

    projTextures[ProjectileType::LONGRANGE] =
        &a.loadTexture("../assets/bullets/bullet_longrange.png");

    projTextures[ProjectileType::ROCKET] =
        &a.loadTexture("../assets/bullets/bullet_check.png");

    projTextures[ProjectileType::SLOWCANNON] =
        &a.loadTexture("../assets/bullets/bullet_slowcannon.png");

    projTextures[ProjectileType::STRAIGHT] =
        &a.loadTexture("../assets/bullets/bullet_check.png");

    projTextures[ProjectileType::UZI] =
        &a.loadTexture("../assets/bullets/bullet_check.png");

    projTextures[ProjectileType::EXECUTABLE] =
        &a.loadTexture("../assets/bullets/bullet_exe.png");

    projTextures[ProjectileType::INTERNET] =
        &a.loadTexture("../assets/bullets/bullet_ie.png");

    projTextures[ProjectileType::UPDATE] =
        &a.loadTexture("../assets/bullets/bullet_update.png");
  }

  static Texture2D *get(ProjectileType type) { return projTextures[type]; }

private:
  static inline std::unordered_map<ProjectileType, Texture2D *> projTextures;
};
