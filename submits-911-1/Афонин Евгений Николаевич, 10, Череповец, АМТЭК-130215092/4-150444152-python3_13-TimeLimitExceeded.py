def nok(a,b):
    s=a*b
    while a%b!=0:
        a,b=b,a%b
    return s//b

m=10**18
n,k=int(input()),int(input())
for i in range(n+1,n+k+1):
    t=nok(n,i)
    if t<m:
        m=t
        k=i
print(k)