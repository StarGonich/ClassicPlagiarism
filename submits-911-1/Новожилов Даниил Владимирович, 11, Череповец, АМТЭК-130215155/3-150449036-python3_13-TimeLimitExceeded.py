n=int(input())
t=int(input())
a=[0]*2*(n+1)
for i in range (1,2*n+1,2):
    b,e=map(int,input().split())
    a[i],a[i+1]=b,e
if a[2*n]<t:
    print(a[2*n])
else:
    s=0
    while s<t and i<a[2*n]-t:
        s=0
        for j in range (1,n+1,2):
            for i in range(a[j],a[j+1]+1):
                s=a[j+1]-i
                u=0
                while a[u]<i+t:
                    u+=2
                u=u-2
                for o in range(i+2,u,2):
                    s=s+a[o+1]-a[o]
                s=s-a[u+2]+i+t
    print(i)