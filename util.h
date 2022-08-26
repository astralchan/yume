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

#ifndef UTIL_H
#define UTIL_H

// Includes

#include <stdio.h>

// Defines

// Error code for readfile
#define READ_FILE_ERROR 1

// Prototypes

// Wrapper for malloc
void *xmalloc(size_t size);
// Wrapper for realloc
void *xrealloc(void *ptr, size_t size);
// Read a file into a string
char *readfile(const char file[]);

#endif // UTIL_h
