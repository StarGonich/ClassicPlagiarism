h=3600
n=int(input())
t=int(input())
inter=[]
for x in range(n):
    i=list(map(int,input().split(' ')))
    inter.append(i)

for x in inter:
    p=inter.index(x)
    
    if x[0]>=3600:
        for y in inter[inter.index(x):]:
            y[0]=y[0]-3600
            y[1]=y[1]-3600
            indizm=p
    elif x[1]>=3600:
        s=x[1]
        x[1]=3600
        inter.insert(p+1,[3600,s])
        for y in inter[p+1:]:
            y[0]=y[0]-3600
            y[1]=y[1]-3600
            indizm=p+1
    else: indizm=0
#print(inter)
                    
raz=0
for x in inter:
    if inter.index(x)==indizm:
        raz=0
    raz+=x[1]-x[0]
    if raz>=t:
        n1=x
        break
    else:
        n1=(-1)
#print(n1)
#print(raz)

if n1==(-1):
    print(n1)
else:
    prev=n1[0]+(t-(raz-(n1[1]-n1[0])))+1
    print(prev)
