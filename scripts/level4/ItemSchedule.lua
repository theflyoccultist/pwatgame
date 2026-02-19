local item_spawn = require("common.item_spawn_patterns")

FoodSpawns = {
	{ x = 50, y = 150, delay = 0.0, type = "yopokki", ammoBonus = 50 },
	{ x = 50, y = 150, delay = 24.2, type = "buldak", ammoBonus = 50 },
	{ x = 450, y = 150, delay = 24.2, type = "buldak", ammoBonus = 50 },
	{ x = 596, y = 150, delay = 24.3, type = "shinramyun", ammoBonus = 50 },
	{ x = 26, y = 59, delay = 78.3, type = "buldak", ammoBonus = 60 },
	{ x = 658, y = 120, delay = 78.3, type = "strawberry", ammoBonus = 50 },
	{ x = 189, y = 150, delay = 107.2, type = "pizza", ammoBonus = 50 },
	{ x = 461, y = 451, delay = 107.2, type = "tomyum", ammoBonus = 50 },
	{ x = 349, y = 691, delay = 107.2, type = "pasta", ammoBonus = 50 },
	{ x = 18, y = 555, delay = 107.2, type = "toast", ammoBonus = 50 },
}

item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(5, 138, "yopokki", 50))

DrinkSpawns = {
	-- uncomment for cheating and testing
	--	{ x = 450, y = 550, delay = 0.0, type = "soju", hpBonus = 20000 },

	{ x = 250, y = 650, delay = 0.0, type = "soju", hpBonus = 50 },
	{ x = 150, y = 700, delay = 24.0, type = "estrogen", hpBonus = 50 },
	{ x = 650, y = 650, delay = 24.0, type = "skirt", hpBonus = 20 },
	{ x = 260, y = 680, delay = 24.0, type = "thighhigh", hpBonus = 20 },
	{ x = 660, y = 664, delay = 48.3, type = "monster", hpBonus = 150 },
	{ x = 694, y = 666, delay = 48.3, type = "estrogen", hpBonus = 70 },
	{ x = 555, y = 459, delay = 48.4, type = "estrogen", hpBonus = 56 },
	{ x = 701, y = 699, delay = 48.6, type = "thighhigh", hpBonus = 88 },
	{ x = 120, y = 659, delay = 78.3, type = "monster", hpBonus = 80 },
	{ x = 666, y = 666, delay = 78.3, type = "coffeemug", hpBonus = 40 },
	{ x = 711, y = 549, delay = 78.3, type = "skirt", hpBonus = 80 },
	{ x = 16, y = 589, delay = 99.5, type = "estrogen", hpBonus = 50 },
	{ x = 199, y = 694, delay = 103.7, type = "skirt", hpBonus = 60 },
}

item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(5, 104.6, "monster", 80))
item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(5, 111, "thighhigh", 70))
item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(5, 143, "estrogen", 50))

WeaponSpawns = {
	{ x = 400, y = 400, delay = 0.0, type = "straight", ammoBonus = 0 },
	{ x = 230, y = 331, delay = 20.0, type = "rocket", ammoBonus = 10 },
	{ x = 30, y = 631, delay = 69.0, type = "grenade", ammoBonus = 10 },
	{ x = 14, y = 199, delay = 86.0, type = "uzi", ammoBonus = 100 },
}
