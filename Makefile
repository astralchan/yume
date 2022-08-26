# vim: ts=4 sw=4 noet cc=80

# Copyright 2022 Astral
#
# This file is part of yume.
#
# yume is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# yume is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# yume. If not, see <https://www.gnu.org/licenses/>.

.POSIX:

# Build variables

CFLAGS  = -O1 `pkg-config --cflags epoxy glfw3 gtk4`
LDFLAGS = `pkg-config --libs epoxy glfw3 gtk4`

# Install variables

DESTDIR =
PREFIX  = /usr/local

# Build rules

all: yume

yume: yume.o util.o engine.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ yume.o util.o engine.o
yume.o: yume.c util.h engine.h
util.o: util.c util.h
engine.o: engine.c engine.h

clean:
	@rm -f yume yume.o util.o engine.o

# Install rules

install:
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp yume $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/yume
	mkdir -p $(DESTDIR)$(PREFIX)/share/man/man1
	cp yume.1 $(DESTDIR)$(PREFIX)/share/man/man1
	chmod 644 $(DESTDIR)$(PREFIX)/share/man/man1/yume.1
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/yume
	rm -f $(DESTDIR)$(PREFIX)/share/man/man1/yume.1
