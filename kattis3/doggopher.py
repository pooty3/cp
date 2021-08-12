import sys
from math import *
def dst(xx1,yx1,xx2,yx2):
	return sqrt(abs(xx1-xx2)**2 + abs(yx1-yx2)**2)
x1,y1,x2,y2 = map(float, input().split())
for line in sys.stdin:
	xx,yy = line.split()
	x = float(xx)
	y = float(yy)
	if (dst(x,y,x1,y1)*2 < dst(x,y,x2,y2)):
		print('The gopher can escape through the hole at ({0},{1}).'.format(xx,yy))
		sys.exit()
print("The gopher cannot escape.")