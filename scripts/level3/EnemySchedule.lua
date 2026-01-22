local timings = require("common.timings")

EnemySpawns = {
	-- { x = 10, y = 30, delay = 0, type = "godsip" },
	-- { x = 600, y = 100, delay = 0, type = "duo" },
	-- { x = 397, y = 500, delay = 0, type = "clank" },
	-- { x = 200, y = 400, delay = 0, type = "clank" },
	-- { x = 340, y = 700, delay = 0, type = "clank" },
	-- { x = 600, y = 400, delay = 0, type = "clank" },

	-- should be mini boss spawn time + 12
	{ x = 200, y = 400, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 300, y = 600, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 100, y = 100, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 650, y = 400, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 100, y = 650, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },

	{ x = 200, y = 400, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 300, y = 600, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 100, y = 100, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 650, y = 400, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 100, y = 650, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
}
