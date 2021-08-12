n = int(input())
mn = 1
mx = 11
while (mx-mn>1e-8):
	md = (mn+mx)/2
	if pow(md,md)>n:
		mx = md
	else:
		mn = md
print(mn)