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

#include "renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <epoxy/gl.h>

#include "util.h"

// Print GL information
void
print_gl_info(void)
{
	printf(
		"GL Vendor: %s\n"
		"GL Renderer: %s\n"
		"GL Version: %s\n"
		"GLSL Version: %s\n",
		glGetString(GL_VENDOR),
		glGetString(GL_RENDERER),
		glGetString(GL_VERSION),
		glGetString(GL_SHADING_LANGUAGE_VERSION)
	);
}

// Initialize a vertex buffer object
void
vboinit(GLsizeiptr size, const GLvoid *data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

// Initialize a vertex array object
void
vaoinit(GLuint index, GLint size, GLsizei stride)
{
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

// Make a shader from a source file
GLuint
makeshader(const GLenum type, const char path[])
{
	// Read shader source in
	const GLchar *src = readfile(path);
	if (!src) return 0;

	// Make shader
	GLuint shader = glCreateShader(type);

	// Build shader
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	// Check the build
	GLint result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

		// Print that error occured
		fprintf(stderr, "Failed to compile shader: %s\n", path);

		// Make char array for log msg
		GLchar *msg = xmalloc(sizeof(GLchar) * length);
		if (!msg) {
			glDeleteShader(shader);
			return 0;
		}

		// Read log into msg
		glGetShaderInfoLog(shader, length, &length, msg);
		fputs(msg, stderr);
		free(msg);

		glDeleteShader(shader);
		return 0;
	}

	return shader;
}
