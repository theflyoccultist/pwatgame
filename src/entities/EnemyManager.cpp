#include "EnemyManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../sound/AudioSystem.hpp"
#include "Enemy.hpp"
#include <raylib.h>

void EnemyManager::init() { factory.loadAssets(); }

void EnemyManager::spawnEnemies(EnemyType type, int count) {
  enemies.reserve(enemies.size() + count);
  for (int i = 0; i < count; ++i) {
    Vector2 pos = {Random::rangeFloat(0, 730.0f),
                   Random::rangeFloat(0, 730.0f)};

    auto e = factory.create(type, pos);

    if (e)
      enemies.push_back(std::move(e));
  }
}

void EnemyManager::applyPlayerDmg(const PlayerState &player, int damage) {
  if (player.damageCooldown <= 0.0f) {
    player.health -= damage;
    player.damageCooldown = 0.10f;
  }
}

void EnemyManager::updateAll(float delta, const PlayerState &player,
                             std::span<Projectile *const> bullets) {
  using namespace Collisions;

  if (player.damageCooldown > 0.0f)
    player.damageCooldown -= delta;

  for (auto &e : enemies) {
    e->update(delta, player.position);

    for (auto &b : bullets) {
      if (b->faction == Faction::Player &&
          checkBulletInteraction(b->position, b->size, e->position, e->size)) {
        player.score++;
        b->expire();
        if (e->takeBulletIfHit(b->damage)) {
          AudioSystem::instance().enemyKilled();
        }
      }

      if (b->faction == Faction::Enemy &&
          checkBulletInteraction(b->position, b->size, player.position,
                                 player.playerSize)) {
        applyPlayerDmg(player, b->damage);
        b->expire();
      }
    }

    bool touchPlayer = checkPlayerInteraction(
        player.position, player.playerSize, e->position, e->size);

    Vector2 bulletStartPos = {e->position.x + (float)e->size / 2,
                              e->position.y + (float)e->size / 2};

    if (e->type == EnemyType::SWARMER && touchPlayer) {
      applyPlayerDmg(player, 4);
    }

    if (e->type == EnemyType::SNIPER) {
      e->shootTowardsPlayer(projMan, {bulletStartPos, player.position, delta,
                                      3.f, ProjectileType::LONGRANGE});
    }

    if (e->type == EnemyType::GODSIP && touchPlayer) {
      applyPlayerDmg(player, 10);
    }

    if (e->type == EnemyType::ZOMB) {
      e->shootInVoid(
          projMan,
          {bulletStartPos, {0, 0}, delta, 6.f, ProjectileType::SLOWCANNON});
    }
  }

  std::erase_if(enemies, [](auto &p) { return !p->isAlive(); });

  enemyCount = enemies.size();
}

void EnemyManager::drawAll() {
  for (auto &e : enemies)
    e->draw();
}

void EnemyManager::clearAll() {
  enemies.clear();
  enemyCount = 0;
}
