#!/bin/bash

cd src
awk '!seen[$0]++ || !/^#include/' *.c > ../string.c
cd ..
