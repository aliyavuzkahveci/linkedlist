#!/bin/bash

# removing previously built binary
rm linkedlist

# cleaning old build
rm -rf build/

# creating build folder
mkdir build

cd build/

# preparation of Makefile
cmake ..

# compile & build
make

# copying the binary to the rott project folder
cp linkedlist ../

# starting binary
./linkedlist
