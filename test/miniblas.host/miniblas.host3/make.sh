#!/bin/bash
SECONDS=0

rm -r build
mkdir build
cd build
cmake -DSYMPIC_MAPU=ON ..
make >&out.log
./bin/sympic >out2.log

echo "total time: ${SECONDS} seconds"