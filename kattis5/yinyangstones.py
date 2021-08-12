s = input()
c = 0
for ch in s:
    c += (1 if ch == 'W' else -1)

print(1 if c ==0 else 0)