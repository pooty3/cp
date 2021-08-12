import sys
n,k = map(int, input().split())

print("Your wish is granted!" if k>351 or (2**k) >= n else "You will become a flying monkey!")
