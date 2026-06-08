def f(x,n):
    global k,a
    if len(x)==n and k==0:
        s=sum(x)
        k=1
        for c in x:
            if s%c!=0:
                k=0
                break
        if k==1:
            print(s)
            print(*x)
    else:
        if k==0:
            for i in range(x[-1]+1,31):
                if not i in x:
                    f(x+[i],n)
k=0
n=int(input())
for i in range(1,31):
    f([i],n)
    