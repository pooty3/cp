from math import *
t = int(input())
for _ in range(t):
	n,m = map(int, input().split())
	print(factorial(n)//factorial(m-1)//factorial(n-m+1))
	