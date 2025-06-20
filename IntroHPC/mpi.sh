#!/bin/bash

mpic++ -std=c++17 -g -fsanitize=undefined,thread mpi.cpp
mpirun -np 1 ./a.out
mpirun -np 2 ./a.out
mpirun -np 4 ./a.out