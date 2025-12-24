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
	make_weapon("lambda", 700, 0.55, 50, 25, 17),
	make_weapon("paren", 500, 0.69, 30, 6, 9),

	-- Enemy projectiles
	make_weapon("longrange", 400, 2.3, 21, 3, 8),
	make_weapon("slowcannon", 150, 0.15, 25, 6, 25),
	make_weapon("recon", 300, 0.8, 45, 3, 3),

	-- Player projectiles
	make_weapon("straight", 2200, 0.2, 5, 1.6, 10),
	make_weapon("uzi", 2500, 0.12, 6, 2.1, 6),
	make_weapon("rocket", 495, 0.9, 45, 5, 53),
	make_weapon("hellfire", 100, 0.1, 60, 2, 100),
	make_weapon("grenade", 900, 2.0, 150, 3, 300),
}
