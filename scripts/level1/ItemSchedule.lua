local item_spawn = require("common.item_spawn_patterns")

FoodSpawns = {
	{ x = 50, y = 150, delay = 0.0, type = "yopokki", ammoBonus = 50 },
	{ x = 250, y = 350, delay = 0.0, type = "pho", ammoBonus = 70 },
	{ x = 450, y = 50, delay = 10.0, type = "buldak", ammoBonus = 90 },
	{ x = 294, y = 493, delay = 48.6, type = "pho", ammoBonus = 60 },
	{ x = 13, y = 83, delay = 56.6, type = "buldak", ammoBonus = 90 },
	{ x = 197, y = 213, delay = 59.9, type = "shinramyun", ammoBonus = 110 },
	{ x = 490, y = 513, delay = 71.9, type = "pho", ammoBonus = 75 },
	{ x = 184, y = 674, delay = 106.5, type = "pho", ammoBonus = 75 },
}

item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(4, 21, "shinramyun", 20))
item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(4, 40.2, "tomyum", 25))
item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(18, 100.5, "yopkki", 14))
item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(25, 121.5, "pho", 20))
item_spawn.append(FoodSpawns, item_spawn.bulk_food_spawn(25, 145.4, "buldak", 20))

DrinkSpawns = {
	{ x = 450, y = 550, delay = 0.0, type = "soju", hpBonus = 50 },
	{ x = 50, y = 750, delay = 0.0, type = "monster", hpBonus = 110 },
	{ x = 50, y = 750, delay = 10.0, type = "icecoffee", hpBonus = 90 },
	{ x = 42, y = 669, delay = 31.0, type = "monster", hpBonus = 110 },
	{ x = 564, y = 119, delay = 47.9, type = "soju", hpBonus = 40 },
	{ x = 123, y = 456, delay = 141.9, type = "monster", hpBonus = 80 },
}

item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(4, 26, "calpis", 20))
item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(20, 38, "bobatea", 15))
item_spawn.append(DrinkSpawns, item_spawn.bulk_drink_spawn(15, 58.2, "soju", 15))
item_spawn.append(DrinkSpawns, item_spawn.zoned_drink_spawn(5, 2, 66.3, "monster", 20, 80, 66, 48))
item_spawn.append(DrinkSpawns, item_spawn.zoned_drink_spawn(10, 10, 81.0, "icecoffee", 0, 0, 60, 60, 12))
item_spawn.append(DrinkSpawns, item_spawn.zoned_drink_spawn(3, 5, 108.9, "soju", 0, 0, 60, 80, 30))

WeaponSpawns = {
	{ x = 400, y = 400, delay = 0.0, type = "straight", ammoBonus = 0 },
	{ x = 230, y = 331, delay = 39.0, type = "uzi", ammoBonus = 68 },
	{ x = 680, y = 591, delay = 100.0, type = "rocket", ammoBonus = 10 },
}
