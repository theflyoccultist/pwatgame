-- All weapon data at their initial values.
-- If you remove this file the game levels refuses to start...

Weapons = {
	-- Miniboss projectiles
	{ type = "exe", speed = 450, fireRate = 0.015, size = 40, lifetime = 3, damage = 7 },
	{ type = "ie", speed = 700, fireRate = 0.25, size = 50, lifetime = 3, damage = 5 },
	{ type = "update", speed = 800, fireRate = 0.10, size = 69, lifetime = 5, damage = 7 },
	{ type = "lambda", speed = 700, fireRate = 0.55, size = 50, lifetime = 20, damage = 9 },
	{ type = "paren", speed = 700, fireRate = 0.55, size = 50, lifetime = 20, damage = 9 },
	{ type = "elixir", speed = 1000, fireRate = 0.30, size = 54, lifetime = 3, damage = 6 },

	-- Enemy projectiles
	{ type = "longrange", speed = 400, firetate = 2.3, size = 21, lifetime = 3, damage = 8 },
	{ type = "slowcannon", speed = 250, fireRate = 2.0, size = 50, lifetime = 3, damage = 3 },
	{ type = "recon", speed = 300, fireRate = 0.8, size = 45, lifetime = 5, damage = 3 },

	-- Player projectiles
	{ type = "straight", speed = 900, fireRate = 0.2, size = 30, lifetime = 1.6, damage = 10 },
	{ type = "uzi", speed = 2500, fireRate = 0.12, size = 10, lifetime = 1.7, damage = 6 },
	{ type = "rocket", speed = 1200, fireRate = 0.9, size = 45, lifetime = 2, damage = 53 },
	{ type = "hellfire", speed = 100, fireRate = 0.1, size = 68, lifetime = 2, damage = 100 },
	{ type = "grenade", speed = 900, fireRate = 2.0, size = 150, lifetime = 3, damage = 300 },
}
