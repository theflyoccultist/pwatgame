-- weapon characteristics are configurable without recompiling

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
	make_weapon("longrange", 400, 1.0, 8, 8, 5, 0),
	make_weapon("slowcannon", 800, 0.7, 20, 6, 3, 0),
	make_weapon("straight", 1600, 1.1, 5, 1.6, 55, 0),
	make_weapon("uzi", 1100, 0.4, 6, 2.1, 7, 0),
	make_weapon("rocket", 1200, 2.1, 30, 4, 46, 0),
}
