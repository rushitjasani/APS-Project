import random
import sys
from sortedcontainers import SortedSet

# n = int(raw_input())
# n=100
n = int(sys.argv[1])
s=SortedSet()

def gen_random(r):
    x=random.randint(0,r)
    if x in s:
        gen_random(r)
    else:
        s.add(x)
    return x

print n
for i in xrange(n):
    opt=random.randint(0,6)
    l=[0,4,5,6]
    if opt in l:
        num=gen_random(65535)
        print 0,num
    elif opt==1:
        print opt 
    elif opt==2:
        print opt
        if len(s)>0:
            s.discard(s[0])
    elif opt==3:
        if len(s)==0:
            print 1
            continue
        elif len(s)-1==0:
            index=0
        else:
            index=random.randint(0,len(s)-1)
        to_change=s[index]
        print opt,to_change,gen_random(to_change)
        s.discard(to_change)
    else:
        pass


