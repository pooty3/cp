n = int(input())
mn =0
sec =0
for i in range(n):
	m, s = map(int,input().split())
	mn += m
	sec += s
amt = sec/60/mn
print("measurement error" if amt <= 1 else amt)
