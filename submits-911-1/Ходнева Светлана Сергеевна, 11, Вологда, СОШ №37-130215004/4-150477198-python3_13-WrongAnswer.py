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
            ch=ch/ch
            a.append(ch)
    return a
n=int(input())
k=int(input())
nok1=[]
b1=np(n)
p=[]
for i in range(n+1,n+k+1):
    b2=np(i)
    for r1 in b1:
        b2.append(r1)
    nok=1
    sp=[]
    for r1 in b2:
        if sp.count(r1)==0:
            sp.append(r1)
    for r in sp:
        nok=nok*max(b1.count(r),b2.count(r))*r
    nok1.append(nok)
    p.append(i)
print(p[nok1.index(min(nok1))])