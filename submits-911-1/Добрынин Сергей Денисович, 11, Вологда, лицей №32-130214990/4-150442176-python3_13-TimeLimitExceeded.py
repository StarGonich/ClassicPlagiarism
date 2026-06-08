n=int(input())
k=int(input())
m=n+k
l=n+1
s=0
o=10000
isk=0
io=n%2
for i in range(l,m+1):
    ty=max(i,n)
    if io==0:
        yu=n
        while yu<=n*i+1:
            if ((yu%n==0) and (yu%i==0)):
                s=yu
                break
            yu+=2
    else:
        for e in range(ty,n*i+1):
            if ((e%n==0) and (e%i==0)):
                s=e
                break
    if s<o:
        o=s
        isk=i
print(isk)
