from math import *
n = int(input())
for _ in range(n):
	x = int(input())
	print(factorial(2*x)//factorial(x)//factorial(x)//(x+1))
