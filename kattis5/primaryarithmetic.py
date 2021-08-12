while True:
    v1,v2 = input().split()
    if v1 == "0" and v2 == "0":
        break
    v1 = v1.rjust(max(len(v1), len(v2)),'0')
    v2 = v2.rjust(max(len(v1), len(v2)),'0')
    v1 = v1[::-1]
    v2 = v2[::-1]
    carry = 0
    c = 0
    for i in range(0, len(v1)):
        val = int(v1[i]) + int(v2[i]) + carry
        if val>9:
            c+=1
            carry =1
        else:
            carry=0
    print("No" if c ==0 else str(c), end="") 
    print(" carry operation", end="") 
    print("s." if c>1 else ".")
