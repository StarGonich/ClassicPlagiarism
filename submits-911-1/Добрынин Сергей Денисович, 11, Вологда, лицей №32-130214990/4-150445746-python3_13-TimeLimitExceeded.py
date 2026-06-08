n=int(input())
k=int(input())
m=n+k
l=n+1
s=0
o=10000000000000000000000000000000000000000000000000000000000000
isk=0
for i in range(l,m+1):
    po=n
    while (po<=n*i):
        if (po%i==0):
            s=po
            break
        po=po+n
    if s<o:
        o=s
        isk=i
print(isk)
