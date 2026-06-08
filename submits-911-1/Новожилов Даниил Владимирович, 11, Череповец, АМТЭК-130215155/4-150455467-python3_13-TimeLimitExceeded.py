n=int(input())
k=int(input())
m=1000000000000
c=0
o=0
for i in range(n+1,n+k+1):
    if i%n==0 and c!=1:
        print(i)
        c=1
        break
    elif c!=1:
        a=n
        b=i
        while a!=b:
            if a>b:
                a=a-b
            if b>a:
                b=b-a
        d=i*n//a
        if d<m:
            m=d
            o=i
if c!=1:
    print(o)