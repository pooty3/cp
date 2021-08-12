def getnum(b, v):
	cur = 0
	for c in v:
		cur*=b
		cur += int(c)
	return cur
def convert(b,v):
	if v == 0:
		return "0"
	s = ""
	while v != 0:
		s += str(v%b)
		v//=b
	return s[::-1]
while True:
	ss = input()
	if ss== "0": 
		break
	b,p,m = ss.split()
	pp = getnum(int(b), p)
	mm = getnum(int(b), m)
	if m == "0":
		print(p)
	else :
		res = pp%mm
		print(convert(int(b),res))

