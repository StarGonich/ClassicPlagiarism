def evk(a,b):
    a1=a
    b1=b
    while b!=0:
        a,b=b,a%b
    return (a1*b1//a)
n=int(input())
k=int(input())
n1=n
a=0
if k>=n:
    print(2*n)
else:
    for i in range(2,int(n**0.5)+2):
        if n1/i==n1//i:
            a=i
            print(a)
            break
    if a==0 or n//a*(a+1)>(n+k):
        print(n+1)
    else:
        print(n//a*(a+1))   