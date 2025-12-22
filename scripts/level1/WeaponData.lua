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
	make_weapon("exe", 450, 0.015, 40, 3, 7),
	make_weapon("ie", 700, 0.25, 50, 3, 5),
	make_weapon("update", 800, 0.10, 69, 5, 7),

	-- Enemy projectiles
	make_weapon("longrange", 400, 1.0, 15, 3, 5),
	make_weapon("slowcannon", 300, 0.15, 35, 3, 1),
	make_weapon("recon", 300, 0.22, 35, 3, 3),

	-- Player projectiles
	make_weapon("straight", 750, 0.3, 20, 1.6, 10),
	make_weapon("uzi", 1100, 0.18, 25, 2.1, 8),
	make_weapon("rocket", 1200, 0.3, 30, 2, 46),
}
