# Fibonacci heap and its applications

This repository contains
* implementation of fibonacci heap 
* implementation of binary heap
* comparison of binary and fibonacci heap
* implementation and comparison of Dijkstra's SSSP algorithm using both heaps
* implementation and comparison of Prim's MST algorithm using both heaps

## Prerequisites

```
sudo apt install python2.7 python-pip
pip install sortedcontainers --user
pip install matplotlib --user
sudo apt-get install python-tk
sudo apt-get install g++
  
```

## Directory Structure
```
.
├── binary_heap
│ ├── binary_heap.h
│ └── binary_heap_test.cpp
├── dijkstra_sssp_algorithm
│ ├── dijkstra_bin.cpp
│ └── dijkstra_fibo.cpp
├── fibonacci_heap
│ ├── fibonacci_heap.h
│ └── fibonacci_heap_test.cpp
├── prims_mst_algorithm
│ ├── prims_bin.cpp
│ └── prims_fibo.cpp
├── readMe.md
└── scripts
├── compare.py
├── dijkstra_tc.py
├── plot1.py
├── plot.py
├── prims_tc.py
├── testcase_generator.py
├── test_dij.sh
├── test_prim.sh
├── test.sh
└── tmp
```

## To check heaps manually

#### Input format
* first line contains number of operations N.
* next N lines contains one of the following operations:
```
  0 x    :- to insert x into heap
  1      :- to get minimum from heap
  2      :- to extract minimum from heap
  3 x y  :- to decrease x to y in heap
```

#### Fibonacci heap
```
 cd fibonacci_heap
 g++ fibonacci_heap_test.cpp
 ./a.out
```

#### Binary heap
```
cd binary_heap
g++ binary_heap_test.cpp
./a.out
```

#### To run and compare both heaps on random inputs
test.sh :
It first compiles both the heaps then generate random input in file
tmp/input by running testcase_generator.py for operations ranging
from 100 to 3000 in gaps of 150 and runs both the heaps on this input
files and stores their output ( tmp/fibo_out and tmp/bin_out ) and
running times( tmp/fibo_time and tmp/bin_time ) in their respective
files, compare both outputs by running compare.py and plot their
times using plot1.py.

```
cd scripts
./test.sh
```

## To run Dijkstra’s algorithm

#### Input format
* first line contains number of test cases T.
* first line of each test case contains number of vertices V and edges E in the undirected graph.
* next E lines contains u,v and w :: source, destination and weight of edge.
* last line of each test case contains s which is source vertex for single source shortest path algorithm.

#### Dijkstra's SSSP using Fibonacci heap
```
cd dijkstra_sssp_algorithm
g++ dijkstra_fibo.cpp
./a.out
```

#### Dijkstra's SSSP using Binary heap
```
cd dijkstra_sssp_algorithm
g++ dijkstra_bin.cpp
./a.out
```
#### To run and compare Dijkstra’s algorithm on random inputs
test_dij.sh :
It first compiles both the implementations of Dijkstra’s algorithm
then generate random input in file tmp/input by running
dijkstra_tc.py for operations ranging from 100 to 2000 in gaps of 100
and runs both the implementations on this input files and stores their
output (tmp/fibo_out and tmp/bin_out ) and running times
(tmp/fibo_time and tmp/bin_time ) in their respective files, compare
both outputs by running compare.py and plot their times using
plot.py.

```
cd scripts
./test_dij.sh
```

## To run Prim’s algorithm

#### Input format
* first line contains number of vertices V and edges E in the undirected graph.
* next E lines contains u,v and w :: source, destination and weight of edge.
* last line of each test case contains s which is starting vertex for minimum spanning tree algorithm.

#### Prim's MST using Fibonacci heap
```
cd prims_mst_algorithm
g++ prims_fibo.cpp
./a.out
```

#### Prim's MST using Binary heap
```
cd prims_mst_algorithm
g++ prims_bin.cpp
./a.out
```

#### To run and compare Prim’s algorithm on random inputs
test_prim.sh :
It first compiles both the implementations of Prim’s algorithm then
generate random input in file tmp/input by running prims_tc.py for
operations ranging from 100 to 2000 in gaps of 100 and runs both the
implementations on this input files and stores their output
(tmp/fibo_out and tmp/bin_out ) and running times (tmp/fibo_time
and tmp/bin_time ) in their respective files, compare both outputs by
running compare.py and plot their times using plot.py.

```
cd scripts
./test_prim.sh
```

## References

* Introduction to Algorithms - Book by Charles E. Leiserson, Clifford Stein, Ronald Rivest, and Thomas H. Cormen
* https://en.wikipedia.org/wiki/Fibonacci_heap
* https://www.growingwiththeweb.com/data-structures/fibonacci-heap/overview
* https://web.stanford.edu/class/archive/cs/cs166/cs166.1146/lectures/07/Slides07.pdf
* https://www.youtube.com/playlist?list=PL6c3bOl0t1DEmWKmJ81xLnCB9wh0WggBg
* https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/FibonacciHeaps.pdf


