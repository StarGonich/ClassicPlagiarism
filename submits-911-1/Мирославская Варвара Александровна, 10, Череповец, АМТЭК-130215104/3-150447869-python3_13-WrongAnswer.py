n=int(input())
t=int(input())
s=[0]*(3600*24+1)
for i in range(n):
    a,b=map(int,input().split())
    for j in range(a,b+1):
        s[j]=1
x=0
y=3600
f=True
while y<=b:
    if sum(s[x:y])>t:
        print(x+1)
        f=False
        break
    x+=1
    y+=1
if f:
    print(-1)