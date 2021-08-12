def getstring(a):
	cur = ""
	while a!=0:
		cur += chr(a%26 + ord('a'))
		a//=26
	print(cur, end =" ")
a,b = map(int, input().split())
for i in range(1, b+1):
	getstring(i)