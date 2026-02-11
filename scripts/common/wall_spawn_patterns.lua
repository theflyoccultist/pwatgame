local M = {}

function M.append(dst, src)
	for _, e in ipairs(src) do
		dst[#dst + 1] = e
	end
end

function M.horizontal_walls(start_x, y_pos, delay, delay_step)
	local t = {}
	delay_step = delay_step or 0
	local x = start_x

	for _ = 1, 8 do
		x = x + 100
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y_pos,
			type = "immobile",
			size = 100,
			warningTime = 3.6,
			activeTime = 3.6,
			contactDmg = 30,
			delay = delay,
		}
	end

	return t
end

function M.vertical_walls(x_pos, start_y, delay, delay_step)
	local t = {}
	delay_step = delay_step or 0
	local y = start_y

	for _ = 1, 8 do
		y = y + 100
		delay = delay + delay_step

		t[#t + 1] = {
			x = x_pos,
			y = y,
			type = "immobile",
			size = 100,
			warningTime = 3.6,
			activeTime = 3.6,
			contactDmg = 30,
			delay = delay,
		}
	end

	return t
end

return M
