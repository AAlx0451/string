#!/bin/bash

cd src;
mkdir -p excl;
mv excl/* .;
echo "Included deps";
rm -rf excl
