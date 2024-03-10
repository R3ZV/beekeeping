#!/bin/bash

make
make clean
astyle --recursive "*.h"  --recursive "*.cpp"
