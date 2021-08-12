c, n =map(int, input().split())
cur =0
able = True
for _ in range(n):
	l,e,s = map(int, input().split())
	if cur < l:
		able = False
	cur += (e-l)
	if cur<0 or cur>c or (cur!=c and s!=0):
		able = False
print("possible" if able and cur == 0 else "impossible")