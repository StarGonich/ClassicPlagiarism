def nok(n,p):
    if n%p==0:
        return n
    elif p%n==0:
        return p
    else:
        for i in range(1,n*p+1):
            if i%n==0 and i%p==0:
                return i
n=int(input())
k=int(input())
minnok=999999999999999
minp=9999999999999999
for p in range(n+1,k+n+1):
    if minnok>nok(n,p):
        minnok=nok(n,p)
        minp=p
print(minp)