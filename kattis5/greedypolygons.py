from math import tan, pi
zz = int(input())
for sss in range(0, zz):
    n,l,d,g = map(int, input().split())
    ini = n * (l**2) / (4*tan(pi/n))
    exa = d * g
    final = ini + exa * l * n + pi*exa**2
    print(final)
