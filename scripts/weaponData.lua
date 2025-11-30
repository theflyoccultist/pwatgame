-- weapon characteristics are configurable without recompiling

local function make_weapon(type, speed, fireRate, size, lifetime, damage)
	return {
		type = type,
		speed = speed,
		fireRate = fireRate,
		size = size,
		lifetime = lifetime,
		damage = damage,
	}
end

Weapons = {
	make_weapon("longrange", 400, 1.0, 8, 3, 5),
	make_weapon("slowcannon", 800, 0.1, 20, 3, 1),
	make_weapon("straight", 1600, 1.1, 5, 1.6, 10),
	make_weapon("uzi", 1100, 0.18, 6, 2.1, 7),
	make_weapon("rocket", 1200, 1.7, 30, 2, 46),
}
