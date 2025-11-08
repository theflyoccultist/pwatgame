#include "../entities/EnemyManager.hpp"
#include "../items/ItemsManager.hpp"
#include "../utils/Scheduler.hpp"
#include <raylib.h>
#include <span>

class SpawnScheduler {
public:
  void init() { enemyManager.init(); }

  void clearAllEnemies() { enemyManager.clearAll(); }

  void scheduleItems() {
    itemManager.populateItems(10, 10);

    scheduler.schedule(15.0f, [&itemManager = itemManager] {
      itemManager.populateItems(2, 5);
    });

    scheduler.schedule(60.0f, [&itemManager = itemManager] {
      itemManager.populateItems(7, 0);
    });
  }

  void scheduleEnemies() {
    enemyManager.spawnEnemies(EnemyType::SNIPER, 10);

    scheduler.schedule(5.0f, [&enemyManager = enemyManager] {
      enemyManager.spawnEnemies(EnemyType::GODSIP, 4);
    });

    scheduler.schedule(10.0f, [&enemyManager = enemyManager] {
      enemyManager.spawnEnemies(EnemyType::SWARMER, 5);
    });

    scheduler.schedule(30.0f, [&enemyManager = enemyManager] {
      enemyManager.spawnEnemies(EnemyType::SWARMER, 25);
    });

    scheduler.schedule(50.0f, [&enemyManager = enemyManager] {
      enemyManager.spawnEnemies(EnemyType::SNIPER, 10);
    });

    scheduler.schedule(55.0f, [&enemyManager = enemyManager] {
      enemyManager.spawnEnemies(EnemyType::GODSIP, 7);
    });
  }

  void updateScheduler(float deltaTime) { scheduler.update(deltaTime); }

  void updateItems(const PlayerState &pwatState) {
    itemManager.updateItems(pwatState.position, pwatState.playerSize);
    itemManager.drawItems(ItemCategory::Food);
    itemManager.drawItems(ItemCategory::Drink);
  }

  void updateEnemies(float deltaTime, const PlayerState &pwatState,
                     std::span<Projectile *const> bullets) {
    enemyManager.updateAll(deltaTime, pwatState, bullets);
    enemyManager.drawAll();
  }

private:
  Scheduler scheduler;
  EnemyManager enemyManager;
  ItemManager itemManager;
};
