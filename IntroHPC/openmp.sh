#!/bin/bash

g++ -std=c++17 -fopenmp -g -fsanitize=undefined,thread openmp.cpp
echo "Running with 2 threads"
OMP_NUM_THREADS=2 ./a.out
echo "Running with 4 threads"
OMP_NUM_THREADS=4 ./a.out