n,b = map(int, input().split())
print("yes" if n<= (1<<(b+1))-1 else "no")