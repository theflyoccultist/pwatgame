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
	make_weapon("elixir", 800, 0.30, 54, 3, 6),

	-- Enemy projectiles
	make_weapon("longrange", 400, 2.3, 21, 3, 8),
	make_weapon("slowcannon", 150, 0.3, 25, 5, 20),
	make_weapon("recon", 190, 0.15, 25, 3, 10),

	-- Player projectiles
	make_weapon("uzi", 1109, 0.06, 12, 1.8, 8),
	make_weapon("rocket", 495, 0.9, 45, 5, 53),
	make_weapon("grenade", 650, 1.2, 150, 3, 300),
}
