#!/bin/bash

rm -r build
mkdir build
cd build
cmake ..
make >&out.log
./blas >&out2.log