from math import *
import sys
h,v = map(int, input().split())
if v == 0 or v == 180:
	print("safe")
	sys.exit()
val = h/sin(radians(v))
print("safe" if val >0 else -int(val))