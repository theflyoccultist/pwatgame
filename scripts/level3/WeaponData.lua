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
	-- Miniboss projectiles
	make_weapon("exe", 450, 0.008, 40, 3, 7),
	make_weapon("ie", 700, 0.4, 30, 3, 5),
	make_weapon("grenade", 300, 2.0, 120, 3, 100),

	-- Enemy projectiles
	make_weapon("longrange", 400, 1.0, 8, 3, 5),
	make_weapon("slowcannon", 70, 0.6, 10, 15, 1),
	make_weapon("recon", 300, 0.22, 35, 3, 3),

	-- Player projectiles
	make_weapon("straight", 1100, 0.3, 15, 1.6, 14),
	make_weapon("uzi", 666, 0.13, 25, 2.1, 27),
	make_weapon("rocket", 400, 0.8, 75, 2, 100),
	make_weapon("hellfire", 100, 0.1, 60, 2, 70),
}
