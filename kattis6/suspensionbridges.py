from math import *
d, s = map(int, input().split());
minA = 0
maxA = 1e9
while (abs(maxA-minA)>1e-10):
	mid = (minA+maxA)/2
	ss = mid*(cosh(d/(2*mid))-1)
	if ss>s:
		minA = mid
	else:
		maxA = mid
print(2*minA*sinh(d/(2*minA)))