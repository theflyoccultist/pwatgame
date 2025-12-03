// Not added to the game yet! Some NPC characters.

#pragma once

#include "../texture/AssetSystem.hpp"
#include <array>
#include <raylib.h>

class NPC {
protected:
  std::array<Texture2D *, 2> textures;

  struct NPCStats {
    Vector2 pos{};
    float speed = 0.0f;
    int size = 70;
  };

public:
  NPC(const std::array<Texture2D *, 2> textures) : textures(textures) {}

  NPCStats stats;

  void draw() const {}
};

class Pweep : public NPC {
public:
  static std::array<Texture2D *, 2> sharedTextures;
  Pweep() : NPC(sharedTextures) {}

  void setTexture() { textures = sharedTextures; }
};

class NPCManager {
public:
  void loadAssets() {
    auto &assets = AssetSystem::instance();

    Pweep::sharedTextures = {
        &assets.loadTexture("../assets/npc/grey_down.png", 70, 70),
        &assets.loadTexture("../assets/npc/grey_up.png", 70, 70),
    };
  }
};
