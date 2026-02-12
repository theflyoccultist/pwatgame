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

function M.moving_horizontal_walls(start_x, y_pos, delay, delay_step)
	local t = {}
	delay_step = delay_step or 0
	local x = start_x
	local y = y_pos

	for _ = 1, 6 do
		y = y + 150
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y,
			type = "moving",
			axis = "horizontal",
			speed = 150,
			size = 70,
			warningTime = 3.6,
			activeTime = 3.6,
			contactDmg = 20,
			delay = delay,
		}
	end

	return t
end

function M.moving_vertical_walls(x_pos, start_y, delay, delay_step)
	local t = {}
	delay_step = delay_step or 0
	local x = x_pos
	local y = start_y

	for _ = 1, 6 do
		x = x + 150
		delay = delay + delay_step

		t[#t + 1] = {
			x = x,
			y = y,
			type = "moving",
			axis = "vertical",
			speed = 150,
			size = 70,
			warningTime = 3.6,
			activeTime = 3.6,
			contactDmg = 20,
			delay = delay,
		}
	end

	return t
end

return M
