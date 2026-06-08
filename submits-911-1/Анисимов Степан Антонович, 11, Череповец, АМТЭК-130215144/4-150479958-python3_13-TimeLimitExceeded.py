def nk (a,b):
    k=a*b
    while a!=b:
        if a>b:
            a-=b
        else:
            b-=a
    return(k//a)
n=int(input())
k=int(input())
mi=999999
a=0
b=0
for i in range(n+1,n+k+1):
    a=nk(n,i)
    if a<mi:
        mi=a
        b=i
print(b)