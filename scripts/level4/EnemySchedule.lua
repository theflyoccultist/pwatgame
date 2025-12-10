-- enemy type, their time of spawning and their number can be scripted.
-- their x and y positions are randomized.

local function spawn_enemy(type, delay, numEnemies)
	return {
		type = type,
		delay = delay,
		numEnemies = numEnemies,
	}
end

EnemySpawns = {
	spawn_enemy("zomb", 0, 4),
	spawn_enemy("sniper", 8.25, 70),
	spawn_enemy("swarmer", 26.15, 15),
	spawn_enemy("swarmer", 29.45, 20),
	spawn_enemy("godsip", 33.15, 4),
	spawn_enemy("godsip", 35.15, 4),
	spawn_enemy("godsip", 37.15, 4),
	spawn_enemy("godsip", 39.15, 4),
	spawn_enemy("godsip", 41.15, 4),
	spawn_enemy("sniper", 61.05, 26),
	spawn_enemy("swarmer", 73.45, 14),
	spawn_enemy("swarmer", 79.85, 18),
	spawn_enemy("godsip", 84.35, 15),
	spawn_enemy("zomb", 99.15, 10),

	spawn_enemy("monitor", 122.0, 1),
	spawn_enemy("monitor", 123.0, 1),
	spawn_enemy("monitor", 124.0, 1),
	spawn_enemy("monitor", 125.0, 1),
	spawn_enemy("monitor", 126.0, 1),
	spawn_enemy("monitor", 127.0, 1),
}
