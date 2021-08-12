from datetime import *
while True:
	n = int(input())
	if n ==0:
		break
	arr = []
	for _ in range(n):
		arr.append(input())
	arr.sort(key = lambda x: datetime.strptime(x.upper().replace(".",""),'%I:%M %p'))
	for c in arr:
		print(c)
	print()