n=int(input())
t=int(input())
p=dict()
for i in range(n):
    a,b=map(int,input().split())
    p[a]=b-a
    p[a+3600]=-p[a]
print(p)
s=0
for i in sorted(p):
    s+=p[i]
    if s>=t:
        l=i
        break
s-=p[l]
l+=(t-s)
print(l-3600+1)