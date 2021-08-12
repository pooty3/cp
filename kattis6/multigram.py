from collections import *
from math import *
import functools
import sys
s = input()
fre = Counter(s)
gd = functools.reduce(lambda x,y:gcd(x,y), fre.values())
for div in range(gd, 1, -1):
	if gd%div == 0:
		chunk = len(s)//div
		sss = [sorted(s[i:i+chunk]) for i in range(0, len(s), chunk)]
		if (all(sss[0] == x for x in sss)):
			print(s[:chunk])
			sys.exit()

print(-1)