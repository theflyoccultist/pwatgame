local timings = require("common.timings")

local function spawn_miniboss(type, delay)
	return {
		type = type,
		delay = delay,
	}
end

MinibossSpawns = {
	spawn_miniboss("rust", timings.lvl4minibossDelay),
}
