arr = input().split()
print("dae ae ju traeligt va" if sum(map(lambda w: w.find("ae")!=-1, arr))>= 0.4 * len(arr) else "haer talar vi rikssvenska")