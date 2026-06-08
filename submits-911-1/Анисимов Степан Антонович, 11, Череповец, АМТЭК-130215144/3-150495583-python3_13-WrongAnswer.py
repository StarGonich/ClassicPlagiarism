n=int(input())
t=int(input())
a=[]
b=[]
x=0
y=0
s=0
for i in range(n):
    x,y=map(int,input().split())
    a.append(x)
    b.append(y)
a.append(a[-1])
b.append(b[-1])
for i in range(n+1):
    if b[i]-a[i]>=t:
        if b[i]>=3600:
            print(b[i]-3600+1-b[i-1]+a[i-1])
            break
        else:
            print(-1)
            break