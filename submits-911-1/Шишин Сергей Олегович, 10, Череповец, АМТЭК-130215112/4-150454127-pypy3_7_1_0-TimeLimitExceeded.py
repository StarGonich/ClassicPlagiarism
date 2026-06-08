def evk(a,b):
    a1=a
    b1=b
    while b!=0:
        a,b=b,a%b
    return (a1*b1//a)
n=int(input())
k=int(input())
nok=99999999999999
p=0
if k>=n:
    print(2*n)
else:
    for i in range(n+1,n+k+1):
        z=evk(n,i)
        if z<nok:
            nok=z
            p=i
    print(p)