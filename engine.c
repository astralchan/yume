// vim: ts=4 sw=4 noet cc=80

/*
 * Copyright 2022 Astral
 *
 * This file is part of yume.
 *
 * yume is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * yume is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * yume. If not, see <https://www.gnu.org/licenses/>.
 */

#include "engine.h"

// Yume api

unsigned int
yume_object_get_id(object obj)
{
	return obj.id;
}

char *
yume_object_get_name(object obj)
{
	return obj.name;
}

float3
yume_object_get_position(object obj)
{
	return obj.pos;
}

float
yume_object_get_position_x(float3 pos)
{
	return pos.x;
}

float
yume_object_get_position_y(float3 pos)
{
	return pos.y;
}

float
yume_object_get_position_z(float3 pos)
{
	return pos.z;
}

yume_api yume = {
	.object_get_id = yume_object_get_id,
	.object_get_name = yume_object_get_name,
	.object_get_position = yume_object_get_position,
	.object_get_position_x = yume_object_get_position_x,
	.object_get_position_y = yume_object_get_position_y,
	.object_get_position_z = yume_object_get_position_z
};
