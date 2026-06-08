def np(ch):
    a=[]
    while ch>1:
        if ch%2==0:
            a.append(2)
            ch=ch/2
        elif ch%3==0:
            a.append(3)
            ch=ch/3
        elif ch%5==0:
            a.append(5)
            ch=ch/5
        elif ch%7==0:
            a.append(7)
            ch=ch/7
        else:
            if ch!=1:
                a.append(ch)
                ch=ch/ch
    return a
n=int(input())
k=int(input())
nok1=[]
b1=np(n)
sb1=set(b1)
p=[]
for i in range(n+1,n+k+1):
    b2=np(i)
    sb2=set(b2)
    mn=sb1.union(sb2)
    nok=1
    for r in mn:
        nok=nok*max(b1.count(r),b2.count(r))*r
    nok1.append(nok)
    p.append(i)
print(p[nok1.index(min(nok1))])