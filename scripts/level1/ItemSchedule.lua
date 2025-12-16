local item_spawn = require("common.item_spawn_patterns")

FoodSpawns = {
	{ x = 50, y = 150, delay = 0.0, type = "yopokki", ammoBonus = 50 },
	{ x = 250, y = 350, delay = 0.0, type = "pho", ammoBonus = 70 },
	{ x = 450, y = 50, delay = 10.0, type = "buldak", ammoBonus = 90 },
}

item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(4, 21, "shinramyun", 20))

DrinkSpawns = {
	{ x = 450, y = 550, delay = 0.0, type = "soju", hpBonus = 50 },
	{ x = 50, y = 750, delay = 0.0, type = "monster", hpBonus = 110 },
	{ x = 50, y = 750, delay = 10.0, type = "icecoffee", hpBonus = 90 },
	{ x = 42, y = 669, delay = 31.0, type = "monster", hpBonus = 110 },
}

item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(4, 26, "calpis", 20))
item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(20, 38, "bobatea", 15))

WeaponSpawns = {
	{ x = 230, y = 331, delay = 39.0, type = "uzi", ammoBonus = 68 },
}
