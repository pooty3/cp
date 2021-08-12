from math import *
import sys
sss = input()
if len(sss)<=10:
	for i in range(1, 100):
		if factorial(i)== int(sss):
			print(i)
			sys.exit()
else:
	l = len(sss)
	curl = 0
	curi = 1
	while int(curl) + 1< l:
		curi += 1
		curl += log10(curi)
	print(curi)