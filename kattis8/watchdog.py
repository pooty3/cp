tc = int(input())
for _ in range(tc):
	s,h = map(int,input().split())
	harr = []
	for _ in range(h):
		x,y = map(int,input().split())
		harr.append((x,y))
	able = False
	for i in range(s+1):
		if able: 
			break
		for j in range(s+1):
			l = min(i, s-i, j, s-j)
			if all(list(map(lambda x: abs(x[0]-i)**2 + abs(x[1]-j)**2 in range(1, l**2+1) ,harr))) :
				print('{0} {1}'.format(i, j))
				able = True
				break
	if not able:
		print("poodle")