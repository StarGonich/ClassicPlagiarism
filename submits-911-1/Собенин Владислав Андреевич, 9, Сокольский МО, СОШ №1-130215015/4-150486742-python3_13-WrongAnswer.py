def nod(a,b):
    while a!=b:
        if a>b:
            a-=b
        if b>a:
            b-=a
    return a


def nok(a,b):
    return a*b/nod(a,b)


n,k=int(input()),int(input())


p=n+1
ans=nok(p,n)
for p in range(n+1,n+k+1):
    ans=min(nok(p,n),ans)


print(int(ans))
