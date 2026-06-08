n=int(input())
k=int(input())
for i in range(n+1,n+k+1):
    a=n
    b=i
    while a!=0 and b!=0:
        if (a>b):
            a=a%b
        else:
            b=b%a
    c=n*i//(a+b)
    if(i==n+1 or c<min):
        min=c
        p=i
print(p)