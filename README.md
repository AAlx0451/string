## libstring

Tiny embeddable <string.h> implementation. 

No locale supoort (excl. POSIX/C)

## How to build it

Run make.sh

For amalgation build (one file) use amalgation.sh

For Small-Libc run libc/mkobjs.sh, then goto ./libc/objs

## Dependencies

1. Sprintf. You can use [this one](https://github.com/mpaland/printf)
2. Putchar (for printf). You can implement it yourselves
3. Malloc (take any from GitHub or implement yourselves. Also, you can exclude it with strdupexcl.sh)

That's it!

## Licence

MIT. Just use it :)
