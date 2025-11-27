#!/bin/bash

cd src

rm -rf *o

echo "Making all in ./src"
for f in *.c; do clang -c $f -O3; done

echo "Linking C static library"
ar rcs libstring.a *o

rm -rf *o

mv *a ..

echo "Done"

echo -e "\nYou can test this lib with test.sh or use it right now with -L. -lstring"

echo -e '\n(for Small-LibC users: prefered way is to run libc/mkobjs.sh and "ar rcs libc.a *o"'
