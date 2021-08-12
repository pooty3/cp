s = input()[::-1]
ss =[s[i:i+3][::-1] for i in range(0,len(s), 3)][::-1]
for v in ss:
	c =0
	for x in v:
		c<<=1
		c += int(x)
	print(c,end="")