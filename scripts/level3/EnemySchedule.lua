local timings = require("common.timings")

EnemySpawns = {
	{ x = 10, y = 30, delay = 0, type = "godsip" },
	{ x = 600, y = 100, delay = 0, type = "duo" },
	{ x = 397, y = 500, delay = 0, type = "clank" },
	{ x = 200, y = 400, delay = 0, type = "clank" },
	{ x = 340, y = 700, delay = 0, type = "clank" },
	{ x = 600, y = 400, delay = 0, type = "clank" },

	{ x = 10, y = 30, delay = 20, type = "godsip" },
	{ x = 100, y = 400, delay = 20, type = "duo" },
	{ x = 397, y = 500, delay = 20, type = "clank" },

	{ x = 10, y = 30, delay = 30, type = "godsip" },
	{ x = 200, y = 700, delay = 30, type = "duo" },
	{ x = 397, y = 500, delay = 30, type = "clank" },

	{ x = 10, y = 30, delay = 35, type = "godsip" },
	{ x = 200, y = 100, delay = 35, type = "duo" },
	{ x = 397, y = 500, delay = 35, type = "clank" },

	{ x = 710, y = 30, delay = 37, type = "godsip" },
	{ x = 540, y = 300, delay = 37, type = "duo" },
	{ x = 397, y = 500, delay = 37, type = "clank" },

	{ x = 710, y = 30, delay = 38, type = "godsip" },
	{ x = 550, y = 600, delay = 38, type = "duo" },
	{ x = 397, y = 500, delay = 38, type = "clank" },

	{ x = 710, y = 30, delay = 39, type = "godsip" },
	{ x = 540, y = 300, delay = 39, type = "duo" },
	{ x = 397, y = 500, delay = 39, type = "clank" },

	-- mini boss spawn time + 12
	{ x = 200, y = 400, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 300, y = 600, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 100, y = 100, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 650, y = 400, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },
	{ x = 100, y = 650, delay = timings.lvl3minibossDelay + 12.0, type = "threademitter" },

	{ x = 400, y = 100, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 300, y = 150, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 100, y = 180, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 650, y = 470, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },
	{ x = 100, y = 690, delay = timings.lvl3minibossDelay + 24.0, type = "threademitter" },

	{ x = 200, y = 400, delay = timings.lvl3minibossDelay + 36.0, type = "threademitter" },
	{ x = 300, y = 600, delay = timings.lvl3minibossDelay + 36.0, type = "threademitter" },
	{ x = 100, y = 100, delay = timings.lvl3minibossDelay + 36.0, type = "threademitter" },
	{ x = 650, y = 400, delay = timings.lvl3minibossDelay + 36.0, type = "threademitter" },
	{ x = 100, y = 650, delay = timings.lvl3minibossDelay + 36.0, type = "threademitter" },
}
