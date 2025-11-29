-- item type, x and y position and their time of spawning can be scripted.

local function spawn_item(type, x, y, delay)
	return {
		type = type,
		x = x,
		y = y,
		delay = delay,
	}
end

ItemSpawns = {
	spawn_item("food", 250, 350, 1.0),
	spawn_item("food", 280, 350, 4.0),
	spawn_item("food", 290, 450, 9.5),
	spawn_item("food", 280, 150, 16.8),
	spawn_item("food", 210, 650, 22.1),
	spawn_item("food", 150, 750, 29.0),
	spawn_item("food", 50, 150, 15.0),
	spawn_item("drink", 50, 150, 16.0),
	spawn_item("drink", 50, 180, 18.0),
	spawn_item("drink", 50, 250, 22.0),
	spawn_item("drink", 50, 350, 24.0),
	spawn_item("drink", 50, 390, 31.0),
	spawn_item("drink", 50, 440, 43.0),
	spawn_item("drink", 50, 560, 55.0),
	spawn_item("drink", 50, 650, 67.0),
	spawn_item("weapon", 10, 650, 5.0),
	spawn_item("weapon", 10, 650, 11.0),
	spawn_item("weapon", 10, 650, 19.0),
	spawn_item("weapon", 10, 650, 43.0),
	spawn_item("weapon", 10, 650, 55.0),
	spawn_item("weapon", 10, 650, 64.0),
	spawn_item("weapon", 10, 650, 88.0),
}

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
