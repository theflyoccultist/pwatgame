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
	spawn_enemy("zomb", 1.25, 1),
	spawn_enemy("sniper", 8.25, 3),
	spawn_enemy("swarmer", 26.15, 1),
	spawn_enemy("godsip", 33.15, 1),
	spawn_enemy("zomb", 43.15, 5),
	spawn_enemy("monitor", 43.15, 5),
}
