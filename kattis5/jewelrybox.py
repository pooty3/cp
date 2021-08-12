def vol(x,y,h):
	return h*(x-2*h)*(y-2*h)

tc = int(input())
for ss in range(tc):
	x,y = map(int, input().split())
	mn = 0
	mx = min(x,y)/2
	while (abs(mn-mx)> 1e-9):
		delta = (mx-mn)/3
		m1 = mn + delta
		m2 = mx - delta
		if vol(x,y,m1)<vol(x,y,m2):
			mn = m1
		else:
			mx = m2
	print(vol(x,y,mn))