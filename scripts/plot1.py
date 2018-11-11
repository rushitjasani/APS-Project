import sys
import os
import matplotlib.pyplot as plt

with open("tmp/fibo_time") as f:
    fib_list = f.read().splitlines()
with open("tmp/bin_time") as f:
    bin_list = f.read().splitlines()

fib_list = [ float( i ) for i in fib_list  ]
bin_list = [ float( i ) for i in bin_list  ]

x = [ i for i in range(100,3001,150) ]

plt.plot( x, bin_list , label="bin_heap" )
plt.xlabel("number of operations")
plt.plot( x, fib_list , label="fibo_heap")
plt.ylabel("running time in seconds")
plt.legend(loc='best')
plt.show()