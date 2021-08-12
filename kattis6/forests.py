import sys
from collections import *
d = {}
p, t = map(int, input().split())
for i in range(1, p+1):
	d[i] = []
for line in sys.stdin:
	i,j = map(int, line.split())
	d[i].append(j)
	
ss = set()
for k, v in d.items():
	v.sort()
	ss.add(','.join(map(str, v)))
print(len(ss))