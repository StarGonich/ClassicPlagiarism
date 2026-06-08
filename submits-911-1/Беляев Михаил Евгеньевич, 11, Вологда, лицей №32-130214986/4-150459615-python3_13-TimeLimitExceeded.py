def nok(a,b):
    a,b=max(a,b),min(a,b)
    n=a
    while n%a!=0 or n%b!=0:
        n+=a
    return n
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