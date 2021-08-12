n,e = map(int, input().split())
want = str(1<<e)
print(len([i for i in range(n+1) if str(i).find(want)!=-1]))