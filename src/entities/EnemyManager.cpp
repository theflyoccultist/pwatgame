#include "EnemyManager.hpp"
#include "../collisions/CollisionDetection.hpp"
#include "../sound/AudioSystem.hpp"
#include "Actor.hpp"
#include "Enemy.hpp"
#include "EnemyDatabase.hpp"
#include <raylib.h>

void EnemyManager::init() { factory.loadAssets(); }

void EnemyManager::spawnEnemies(const Vector2 &pos, EnemyType type) {
  for (auto *&slot : enemies) {
    if (!slot || !slot->isActive()) {
      auto &spec = EnemyDatabase::get(type);
      Enemy *e = factory.create(type, pos, spec);

      if (e) {
        slot = e;
        e->activate();
        break;
      }
    }
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

  for (auto *e : enemies) {
    if (!e || !e->isAlive())
      continue;

    e->update(delta, player.position);

    for (auto &b : bullets) {
      if (!b || !b->isActive())
        continue;

      if (b->faction == Faction::Player &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 e->stats.pos, (float)e->stats.size)) {
        player.score++;
        b->expire();

        if (e->takeBulletIfHit(b->stats.damage)) {
          AudioSystem::instance().sfx->enemyKilled();
        }
      }

      if (b->faction == Faction::Enemy &&
          checkBulletInteraction(b->stats.pos, (float)b->stats.size,
                                 player.position, (float)player.playerSize)) {
        applyPlayerDmg(player, b->stats.damage);
        b->expire();
      }
    }

    bool touchPlayer =
        checkPlayerInteraction(player.position, (float)player.playerSize,
                               e->stats.pos, (float)e->stats.size);

    Vector2 bulletStartPos = {e->stats.pos.x + (float)e->stats.size / 2,
                              e->stats.pos.y + (float)e->stats.size / 2};

    Actor::ShootParams p;
    p.startPos = bulletStartPos;
    p.playerPos = player.position;
    p.dt = delta;

    p.type = EnemyDatabase::getWeaponType(e->type);
    p.spec = EnemyDatabase::getWeaponSpec(e->type);

    if (e->type == EnemyType::SWARMER && touchPlayer) {
      applyPlayerDmg(player, 4);
    }

    if (e->type == EnemyType::SNIPER) {
      e->shootTowardsPlayer(projMan, p);
    }

    if (e->type == EnemyType::GODSIP && touchPlayer) {
      applyPlayerDmg(player, 6);
    }

    if (e->type == EnemyType::ZOMB) {
      e->shootInVoid(projMan, p);
    }

    if (e->type == EnemyType::MONITOR && touchPlayer) {
      applyPlayerDmg(player, 3);
    }
  }

  for (auto &e : enemies) {
    if (e && !e->isAlive()) {
      e->deactivate();
      e = nullptr;
    }
  }
}

void EnemyManager::drawAll() {
  for (auto *e : enemies) {
    if (e && e->isAlive())
      e->draw();
  }
}

void EnemyManager::clearAll() {
  for (auto *&p : enemies) {
    if (p) {
      p->deactivate();
      p = nullptr;
    }
  }
}
