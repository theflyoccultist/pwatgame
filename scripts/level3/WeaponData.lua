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
	make_weapon("straight", 1600, 0.3, 5, 1.6, 100),
	make_weapon("uzi", 1100, 0.18, 6, 2.1, 7),
	make_weapon("rocket", 1200, 0.9, 30, 2, 46),
}
