h=3600
n=int(input())
t=int(input())
inter=[]
for x in range(n):
    i=list(map(int,.split(' ')))
    inter.append(i)

raz=0
for x in inter:
    raz+=x[1]-x[0]
    if raz>=t:
        n1=x
        break
    else:
        n1=(-1)
print(n1)
print(raz)

if n1==-1:
    print(n1)
else:
    prev=n1[0]+(t-(raz-(n1[1]-n1[0])))+1
    print(prev)