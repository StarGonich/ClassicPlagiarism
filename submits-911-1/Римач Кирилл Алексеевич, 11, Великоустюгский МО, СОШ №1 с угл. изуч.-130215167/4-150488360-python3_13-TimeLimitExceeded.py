def nok(n,p):
    if n%p==0:
        return n
    elif p%n==0:
        return p
    else:
        flag=False
        for i in range(min(n,p)-1,0,-1):
            if n%i==0 and p%i==0:
                return (n//i)*(p//i)*i
                flag=True
        if flag==False:
            return n*p
n=int(input())
k=int(input())
minnok=999999999
minp=999999999
for p in range(n+1,k+n+1):
    if minnok>nok(n,p):
        minnok=nok(n,p)
        minp=p
print(minp)