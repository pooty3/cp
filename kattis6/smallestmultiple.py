import functools
from math import *
import sys
for line in sys.stdin:
	arr = list(map(int, line.split()))
	print(functools.reduce(lambda a,b: a*b//gcd(a,b),arr))