def nok(a,b):
    a,b=max(a,b),min(a,b)
    n=a
    if prost(a) and prost(b) and a!=b:
        return a*b
    elif a==b:
        return a
    while n%a!=0 or n%b!=0:
        n+=a
    return n
def prost(a):
    for i in range(2,int(a**0.5)+1):
        if a%i==0:
            return 0
    return 1
m=[]
c=[]
n=int(input())
k=int(input())
for p in range(n+1,n+k+1):
    m.append(nok(n,p))
    c.append(p)
minm=min(m)
for i in range(0,len(m)):
    if m[i]==minm:
        print(c[i])
        break
