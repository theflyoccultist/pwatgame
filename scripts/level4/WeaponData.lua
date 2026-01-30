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
	make_weapon("longrange", 400, 3.0, 25, 3, 5),
	make_weapon("slowcannon", 300, 3.5, 80, 3, 10),
	make_weapon("recon", 300, 0.22, 35, 3, 3),

	-- Player projectiles
	make_weapon("straight", 1600, 0.3, 5, 1.6, 100),
	make_weapon("uzi", 1100, 0.18, 6, 2.1, 80),
	make_weapon("rocket", 1200, 0.3, 25, 2, 400),
	make_weapon("hellfire", 100, 0.1, 60, 2, 100),
	make_weapon("grenade", 900, 2.0, 150, 3, 300),
}
