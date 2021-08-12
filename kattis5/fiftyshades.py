n = int(input())
amt =0
for i in range(n):
	s = input().lower()
	amt += (s.find('rose')!=-1 or s.find('pink')!=-1)
if amt == 0:
	print("I must watch Star Wars with my daughter")
else:
	print(amt)