#!/bin/bash

if [ $(basename $(pwd)) == "libc" ]; then
	mkdir -p objs;
	cd objs;
else
	cd libc;
	mkdir -p objs;
	cd objs;
fi

rm -rf *o;

cp ../../src/*.c .;

for f in *.c; do clang -c $f -O3; done

rm -f *.c;

echo "Now you should ar rcs libc.a *.o to add string.h";
