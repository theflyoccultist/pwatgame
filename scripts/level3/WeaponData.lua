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

	-- Enemy projectiles
	make_weapon("longrange", 400, 1.0, 8, 3, 5),
	make_weapon("slowcannon", 100, 3.0, 70, 3, 20),
	make_weapon("recon", 300, 0.22, 35, 3, 3),

	-- Player projectiles
	make_weapon("straight", 1100, 0.3, 15, 1.6, 14),
	make_weapon("uzi", 400, 0.13, 25, 2.1, 7),
	make_weapon("rocket", 400, 0.8, 75, 2, 100),
	make_weapon("hellfire", 100, 0.1, 60, 2, 100),
	make_weapon("grenade", 900, 2.0, 150, 3, 300),
}
