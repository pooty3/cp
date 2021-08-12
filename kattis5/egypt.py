while True:
	a,b,c = sorted(map(int, input().split()))
	if a == 0 and b ==0 and c ==0: 
		break
	print("right" if a*a + b*b == c*c else "wrong")