import math
def g(n,k):
    m=float('inf')
    b=n+1
    for p in range(n+1,n+k+1):
        c=n*p // math.gcd(n,p)
        if c<m:
            m=c
            b=p
    return b
n=int(input())
k=int(input())
r=g(n,k)
print(r)
