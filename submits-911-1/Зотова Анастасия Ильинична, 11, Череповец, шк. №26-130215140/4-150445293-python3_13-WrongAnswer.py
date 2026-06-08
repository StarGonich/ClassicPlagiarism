n=int(input())
k=int(input())
p=0
t=1
for i in range(100):
    if p>=n+1 and p<=n+k:
        if t%n==0 and t%p==0:
            print(p)
            break
        else:
            t=+1
    else:
        p=t+1