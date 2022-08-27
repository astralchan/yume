# About

`yume` is a game engine I want to build one day. This repo is mainly focused on
the core of the engine - the entry point, event loop, etc. Graphics / GUI is
something that won't be done for a very long time.

# Dependencies

* ISO/IEC 9899:1999 (C99) library  - e.g. `glibc`, `musl-libc`, etc
* IEEE/Open Group 1003.1-2017 (POSIX.1-2017) `c99` - e.g. `gcc`, `clang`, etc
with:
```
#!/bin/sh
exec cc -std=c99 "$@"
```
* IEEE/Open Group 1003.1-2017 (POSIX.1-2017) `make` - e.g. `gmake`, `bmake`,
`pdpmake`, etc
* `pkg-config`
* `glfw-devel`
* `epoxy-devel`
* `gtk4-devel`

# Building

To build `yume`, run:

```
make
```

# Usage

Currently, there isn't much to do with `yume`. Granted, the final application
could be ran with:

```
./yume
```

# Installation

To install `yume`, run:

```
make install
```

# License

![GPL logo](.img/gpl-logo.png)

`yume` is released under GPLv3 or later. SPDX identifier: `GPL-3.0-or-later`.
For more information, see [`COPYING`](./COPYING), or if more recent,
[https://gnu.org/licenses/gpl.html](https://gnu.org/licenses/gpl.html) for
details.

## Contact

e-mail: [astral@astralchan.xyz](mailto:astral@astralchan.xyz)
