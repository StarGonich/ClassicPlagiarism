n=int(input())
k=int(input())
s=1
p=n+1
l=2**32-1
while p<=n+k:
    x=n
    y=p
    while p%n!=0:
        a=p
        p=n
        n=a%n
    q=x*y/n
    n=x
    p=y
    if q<l:
        l=q
        s=p
    p+=1
print(s)
