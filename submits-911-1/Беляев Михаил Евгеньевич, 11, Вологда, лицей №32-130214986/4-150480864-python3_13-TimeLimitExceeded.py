def nok(a,b):
    a,b=max(a,b),min(a,b)
    c=a*b
    while a%b!=0:
        a=a%b
        a,b=max(a,b),min(a,b)
    return c//b
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
