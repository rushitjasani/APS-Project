#!/bin/bash

rm tmp/bin_time tmp/fibo_time tmp/fibo_out tmp/bin_out tmp/d_fibo tmp/d_bin 2> /dev/null 

g++ ../dijkstra_sssp_algorithm/dijkstra_fibo.cpp -o tmp/d_fibo
echo "dij fibonacci heap compiled"
g++ ../dijkstra_sssp_algorithm/dijkstra_bin.cpp -o tmp/d_bin
echo "dij binary heap compiled"

for i in {100..2000..100}
do 
    python dijkstra_tc.py $i > tmp/input
    echo "TC generated for " $i " vertices"
    ./tmp/d_fibo < tmp/input > tmp/fibo_out
    ./tmp/d_bin < tmp/input > tmp/bin_out
    python compare.py 
done

python plot.py
