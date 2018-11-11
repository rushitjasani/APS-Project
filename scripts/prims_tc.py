from random import *
import sys 

v = int(sys.argv[1])
e = v * (v-1)
print v, e/2

for i in xrange(v):
    for j in xrange(i+1,v):
        print i, j, randint(0,9999)

print randint(0, v)
