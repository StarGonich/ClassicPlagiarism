n=int(input())
a=[1,2,3]
k=0
if n==1:
    print(1)
    print(1)
elif n==2:
    print(-1)
else:
    for i in range(0,n):
        k+=a[i]
        a.append(a[-1]*2)
    print(k)
    print(*(a[:n]))
