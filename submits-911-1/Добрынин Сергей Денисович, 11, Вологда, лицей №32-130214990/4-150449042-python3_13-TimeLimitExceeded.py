n=int(input())
k=int(input())
m=n+k
l=n+1
s=0
o=10000000000000000000000000000000000000000000000000000000000000
isk=0
for i in range(l,m+1):
    for e in range(n,n*i+1):
        if ((e%n==0) and (e%i==0)):
            s=e
            break
    if s<o:
        o=s
        isk=i
        
print(isk)
