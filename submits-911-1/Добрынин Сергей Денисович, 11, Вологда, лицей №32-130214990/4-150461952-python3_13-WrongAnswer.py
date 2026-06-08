n=int(input())
k=int(input())
m=n+k
l=n+1
s=0
il=0
o=10000000000000000000000000000000000000000000000000000000000000
isk=0
for i in range(l,m+1):
    e=n
    while e<=n*i:
        if e%i==0:
            s=e
            break
        e=e+n
    if ((s<o) and (s>0)):
        if (il==3):
            o=s
            isk=i
            break
        o=s
        isk=i
        il=il+1
            
print(isk)
