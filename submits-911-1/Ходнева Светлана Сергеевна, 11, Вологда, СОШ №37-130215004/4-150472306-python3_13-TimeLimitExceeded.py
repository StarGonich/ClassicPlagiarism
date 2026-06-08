def np(ch):
    a=[]
    while ch>1:
        if ch%2==0:
            a.append(2)
            ch=ch/2
        if ch%3==0:
            a.append(3)
            ch=ch/3
        if ch%5==0:
            a.append(5)
            ch=ch/5
        if ch%7==0:
            a.append(7)
            ch=ch/7
    return a
n=int(input())
k=int(input())
nok1=[]
b1=np(n)
p=[]
for i in range(n+1,n+k+1):
    b2=np(i)
    nok=1
    if max(b1.count(2),b2.count(2))!=0:
        nok=nok*max(b1.count(2),b2.count(2))*2
    if max(b1.count(3),b2.count(3))!=0:
        nok=nok*max(b1.count(3),b2.count(3))*3
    if max(b1.count(5),b2.count(5))!=0:
        nok=nok*max(b1.count(5),b2.count(5))*5
    if max(b1.count(7),b2.count(7))!=0:
        nok=nok*max(b1.count(7),b2.count(7))*7
    nok1.append(nok)
    p.append(i)
print(p[nok1.index(min(nok1))])