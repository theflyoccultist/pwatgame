local function create_item(type, x, y, delay)
	return {
		type = type,
		x = x,
		y = y,
		delay = delay,
	}
end

ItemSpawns = {
	create_item("food", 250, 350, 1.0),
	create_item("food", 280, 350, 4.0),
	create_item("food", 290, 450, 9.5),
	create_item("food", 280, 150, 16.8),
	create_item("food", 210, 650, 22.1),
	create_item("food", 150, 750, 29.0),
	create_item("food", 50, 150, 15.0),
	create_item("drink", 50, 150, 16.0),
	create_item("drink", 50, 180, 18.0),
	create_item("drink", 50, 250, 22.0),
	create_item("drink", 50, 350, 24.0),
	create_item("drink", 50, 390, 31.0),
	create_item("drink", 50, 440, 43.0),
	create_item("drink", 50, 560, 55.0),
	create_item("drink", 50, 650, 67.0),
	create_item("weapon", 10, 650, 5.0),
	create_item("weapon", 10, 650, 11.0),
	create_item("weapon", 10, 650, 19.0),
	create_item("weapon", 10, 650, 43.0),
	create_item("weapon", 10, 650, 55.0),
	create_item("weapon", 10, 650, 64.0),
	create_item("weapon", 10, 650, 88.0),
}

local function create_enemy(type, delay, numEnemies)
	return {
		type = type,
		delay = delay,
		numEnemies = numEnemies,
	}
end

EnemySpawns = {
	create_enemy("zomb", 1.25, 1),
	create_enemy("sniper", 8.25, 3),
	create_enemy("swarmer", 26.15, 1),
	create_enemy("godsip", 33.15, 1),
	create_enemy("zomb", 43.15, 5),
	create_enemy("monitor", 43.15, 5),
}
