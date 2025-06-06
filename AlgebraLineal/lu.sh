#!/bin/bash
for a in 1 2 4 8 16; do 
    parallel "OMP_NUM_THREADS=${a} ./lu.x {} 2 2>/dev/null 1>> datos_${a}.txt" ::: 250 500 750 1000 1250 1500 1750 2000; 
done