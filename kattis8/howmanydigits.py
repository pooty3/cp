from math import *
import sys
arr = []
arr.append(1)
curl = 1
for i in range(1, 1000001):
	curl += log10(i)
	arr.append(int(floor((curl))))
for line in sys.stdin:
	print(arr[int(line)])