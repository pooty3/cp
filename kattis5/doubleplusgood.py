ss = input()
arr = ss.split("+")
s = set()
for i in range(0, (1<<(len(arr)-1))):
    numarr = []
    prev = arr[0]
    for j in range(0, len(arr)-1):
        if (1<<j)&i != 0:
            prev += arr[j+1]
        else:
            numarr.append(int(prev))
            prev = arr[j+1]
    numarr.append(int(prev))
    s.add(sum(numarr))
print(len(s))

