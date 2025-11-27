## libstring

Tiny embeddable `<string.h>` implementation. 

No locale supoort (excl. POSIX/C)

## How to build it

Run `make.sh`

For amalgation build (one file) use `amalgation.sh` (with amalgation build you can use some useful flags, see below)

For Small-Libc run `libc/mkobjs.sh`, then goto `./libc/objs`

## Dependencies (Target machine)

1. `sprintf()`. You can use [this one](https://github.com/mpaland/printf)
2. `putchar()` (for printf). You can implement it yourselves
3. `malloc()` (take any from GitHub or implement yourselves. Also, you can exclude it with strdupexcl.sh)

That's it!

## Dependencies (Build machine)

1. A working C compiler called `cc`
2. AWK for header and amalgation build
3. Target's SDK
4. Bash (but should work for any POSIX sh)

## Amalgation and complete independent build

`amalgation.sh` uses awk to make C code look better and adds `NO_FUNC` macros. So, if you want to remove e.g. strtok, use `cc -c string.c -o string.o -DNO_STRTOK`. And for independent build you can use `-DNO_DEPEND`, which removes strerror and strdup.

Anyway, don't use amalgation build if you want a LibC – you'll need to include all <string.h> to your binaries.

## string.h header

It's recommended to write it yourselves, because general header will include all the functions even if you don't need them. But you can use `./makeheader.sh`

## Licence

MIT. Just use it :)
