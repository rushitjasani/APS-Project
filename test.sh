#!/bin/bash
rm fibo bin fibo_out bin_out input
python testcase_generator.py > input
echo "input file created"
g++ -g fibonacci_heap_test.cpp -o fibo
echo "fibonacci heap compiled"
g++ -g binary_heap_test.cpp -o bin
echo "binary heap compiled"
./fibo < input > fibo_out
echo "fibonacci heap"
./bin < input > bin_out
echo "binary heap"
python compare.py
python plot.py