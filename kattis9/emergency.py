n,k = map(int, input().split())
print(min(n-1,1+k+(n-1)-(n-1)//k*k))