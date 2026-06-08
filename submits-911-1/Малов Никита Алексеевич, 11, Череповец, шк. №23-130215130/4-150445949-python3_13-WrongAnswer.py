import math
n=int(input())
k=int(input())
for p in range(0,10**4):
    if p>=n+1 and p<=n+k:
        t=math.gcd(n,k)
        a=n*k//t
        print(t)