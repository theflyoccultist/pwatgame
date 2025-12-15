local M = {}

function M.append(dst, src)
	for _, e in ipairs(src) do
		dst[#dst + 1] = e
	end
end

function M.swarmer_swarm(count, start_x, start_y, dx, dy, delay, delay_step)
	local t = {}
	local x, y = start_x, start_y

	for _ = 1, count do
		x = x + dx
		y = y + dy
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay,
			type = "swarmer",
		}
	end

	return t
end

function M.zomb_chaos(count, delay, delay_step)
	local t = {}

	for _ = 1, count do
		local x = math.random(0, 730)
		local y = math.random(0, 730)
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y,
			delay = delay,
			type = "zomb",
		}
	end

	return t
end

return M
