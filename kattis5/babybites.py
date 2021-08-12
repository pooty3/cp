import sys
n = int(input())
s = input().split()
prev = 0
for w in s:
	if w != "mumble" and prev != int(w) -1:
		print("something is fishy")
		sys.exit()
	prev += 1
print("makes sense")
