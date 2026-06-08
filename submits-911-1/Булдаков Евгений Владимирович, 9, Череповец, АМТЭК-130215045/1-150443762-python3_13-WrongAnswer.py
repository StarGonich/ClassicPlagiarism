h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p1=h1*60
p2=h2*60
s=0
for i in range (p1+m1,p2+m2+1):
    if (i//60==i%60%10*10+i%60//10) or (i//60==i%60) or ((i//60//10+1==i//60%10) and (i//60%10+1==i%60//10) and (i%60//10+1==i%60%10)): s=s+1
print(s)

