from math import gcd
n=int(input())
p=n+1
k=int(input())
m=99999999999
while p>=n+1 and p<=n+k:
    if (n*p//gcd(n,p))<m:
        m=n*p//gcd(n,p)
        o=p
    p+=1
print(o)