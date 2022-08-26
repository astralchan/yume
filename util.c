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

#include "util.h"

#include <stdio.h>
#include <stdlib.h>

// Wrapper for malloc
void *
xmalloc(size_t size)
{
	void *res = malloc(size);
	if (!res) {
		perror("MALLOC ERROR");
		fputs("Failed to allocate memory\n", stderr);
	}
	return res;
}

// Wrapper for realloc
void *
xrealloc(void *ptr, size_t size)
{
	void *res = realloc(ptr, size);
	if (!res) {
		perror("REALLOC ERROR");
		fputs("Failed to reallocate memory\n", stderr);
	}
	return res;
}

// Read a file into a string
char *
readfile(const char file[])
{
	// Open the file
	FILE *fp = fopen(file, "r");
	if (!fp) {
		perror("FOPEN ERROR");
		fprintf(stderr, "Failed to open file: %s\n", file);
		return NULL;
	}

	// Get file size
	if (fseek(fp, 0L, SEEK_END)) {
		perror("FSEEK ERROR");
		fprintf(stderr, "Failed to seek end of file: %s\n", file);
		fclose(fp);
		return NULL;
	}
	long size = ftell(fp);
	rewind(fp);

	// Allocate memory for the file content
	char *content = xmalloc(size + 1);
	if (!content) {
		fclose(fp);
		return NULL;
	}

	// Read file into char pointer
	if (!fread(content, 1, size, fp)) {
		perror("FREAD ERROR");
		fprintf(stderr, "Failed to read file: %s\n", file);
		fclose(fp);
		free(content);
		return NULL;
	}

	// Close the file
	fclose(fp);

	// Null-terminate the file content
	content[size] = '\0';

	return content;
}
