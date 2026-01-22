local function spawn_miniboss(type, delay)
	return {
		type = type,
		delay = delay,
	}
end

MinibossSpawns = {
	spawn_miniboss("java", 1.0),
	-- spawn_miniboss("java", 169.0),
}
