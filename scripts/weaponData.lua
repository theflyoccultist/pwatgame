-- yet to be implemented: weapon characteristics that are configurable without recompiling

local function make_weapon(type, speed, fireRate, size, lifetime, damage, spread)
	return {
		type = type,
		speed = speed,
		fireRate = fireRate,
		size = size,
		lifetime = lifetime,
		damage = damage,
		spread = spread,
	}
end

Weapons = {
	make_weapon("longrange", 400, 0.1, 8, 8, 5, 0),
	make_weapon("slowcannon", 800, 0.7, 1, 6, 10, 0),
	make_weapon("straight", 1600, 0.2, 5, 1.6, 55, 0),
	make_weapon("uzi", 1100, 0.5, 6, 2.1, 88, 0),
	make_weapon("rocket", 1200, 0.6, 3, 4, 46, 0),
}
