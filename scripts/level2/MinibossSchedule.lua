local timings = require("common.timings")

local function spawn_miniboss(type, delay)
	return {
		type = type,
		delay = delay,
	}
end

MinibossSpawns = {
	spawn_miniboss("lisp", timings.lvl2minibossDelay),
}
