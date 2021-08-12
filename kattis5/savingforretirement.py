import math
b,br,bs,a,aa = map(int, input().split())
print(int(math.ceil(((br-b)*bs + 1)/aa)) + a)