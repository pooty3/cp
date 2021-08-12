def candle(n, i):
    return max(n*(n+1)/2 - i*(i+1)/2,0)

d = int(input())
r = int(input())
t = int(input())
tot = r+t
cur = max(d+1,4)
while True:
    if candle(cur, 3) + candle(cur-d, 2) == tot:
        print(int(r-candle(cur,3)))
        break
    else:
        cur+=1
