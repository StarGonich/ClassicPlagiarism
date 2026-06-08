n=int(input())
t=int(input())
s=[0]*3600*24
for i in range(n):
    a,b=map(int,input().split())
    for i in range(a,b+1):
        s[i]=1
x=1
y=3600
f=True
while y<=3600*24:
    if sum(s[x:y])>t:
        print(x)
        f=False
        break
    x+=1
    y+=1
if f:
    print(-1)