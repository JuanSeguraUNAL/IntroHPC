#!/bin/bash

mpic++  mpiInterchange.cpp 
mpirun -np 2 ./a.out