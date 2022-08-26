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

#ifndef ENGINE_H
#define ENGINE_H

typedef struct {
	float x, y, z;
} float3;

typedef struct {
	unsigned int id;
	char *name;
	float3 pos;
} object;

typedef struct {
	unsigned int (*object_get_id)(object obj);
	char *(*object_get_name)(object obj);
	float3 (*object_get_position)(object obj);
	float (*object_get_position_x)(float3 pos);
	float (*object_get_position_y)(float3 pos);
	float (*object_get_position_z)(float3 pos);
} yume_api;

extern yume_api yume;

#endif // ENGINE_H
