#!/bin/bash

rm tmp/bin_time tmp/fibo_time tmp/fibo_out tmp/bin_out tmp/p_fibo tmp/p_bin 2> /dev/null 

g++ ../prims_mst_algorithm/prims_fibo.cpp -o tmp/p_fibo
echo "prim fibonacci heap compiled"
g++ ../prims_mst_algorithm/prims_bin.cpp -o tmp/p_bin
echo "prim binary heap compiled"

for i in {100..2000..100}
do
    python prims_tc.py $i > tmp/input
    echo "TC generated for " $i " vertices"
    ./tmp/p_fibo < tmp/input > tmp/fibo_out
    ./tmp/p_bin < tmp/input > tmp/bin_out
    python compare.py
done

python plot.py
