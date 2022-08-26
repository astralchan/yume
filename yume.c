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

#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "engine.h"

int
main(void)
{
	object astral = { 123, "Astral", {1.0f, 2.0f, 3.0f} };

	printf("Object Info:\n\tID: %d\n\tName: %s\n\tPosition:\n\t\tX: %f\n\t\t"
			"Y: %f\n\t\tZ: %f\n",
			yume.object_get_id(astral),
			yume.object_get_name(astral),
			yume.object_get_position_x(yume.object_get_position(astral)),
			yume.object_get_position_y(yume.object_get_position(astral)),
			yume.object_get_position_z(yume.object_get_position(astral))
			);

	return 0;
}
