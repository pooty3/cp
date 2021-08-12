while True:
	n = int(input())
	if n==0:
		break
	val = []
	n-=1
	ind = 0
	while (1<<ind)<=n:
		if (1<<ind)&n !=0:
			val.append(3**ind)
		ind +=1
	print('{ ', end = '')
	print(', '.join(map(str,val)), end = "")
	print(' }')