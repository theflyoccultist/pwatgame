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
	make_weapon("longrange", 400, 2.3, 21, 3, 8),
	make_weapon("slowcannon", 250, 2.0, 50, 3, 4),
	make_weapon("straight", 2200, 0.2, 5, 1.6, 10),
	make_weapon("uzi", 2500, 0.12, 6, 2.1, 6),
	make_weapon("rocket", 1200, 0.9, 45, 2, 53),
	make_weapon("hellfire", 100, 0.1, 60, 2, 100),
	make_weapon("grenade", 900, 2.0, 150, 3, 300),
}
