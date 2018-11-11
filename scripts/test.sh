#!/bin/bash
rm tmp/fibo tmp/bin tmp/fibo_out tmp/bin_out tmp/input tmp/fibo_time tmp/bin_time

g++ ../fibonacci_heap/fibonacci_heap_test.cpp -o tmp/fibo
echo "fibonacci heap compiled"
g++ ../binary_heap/binary_heap_test.cpp -o tmp/bin
echo "binary heap compiled"

for i in {100..3000..150}
do
    python testcase_generator.py $i > tmp/input
    echo "TC generated for " $i " operations"
    ./tmp/fibo < tmp/input > tmp/fibo_out
    ./tmp/bin < tmp/input > tmp/bin_out
    python compare.py
done
python plot1.py