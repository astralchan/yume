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

#ifndef RENDERER_H
#define RENDERER_H

// Includes

#include <epoxy/gl.h>

// Prototypes

// Print GL information
void print_gl_info(void);
// Initialize a vertex buffer object
void vboinit(GLsizeiptr size, const GLvoid *data);
// Initialize a vertex array object
void vaoinit(GLuint index, GLint size, GLsizei stride);
// Make a shader from a source file
GLuint makeshader(const GLenum type, const char path[]);

#endif // RENDERER_H
