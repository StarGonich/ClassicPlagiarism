n=int(input())
k=int(input())
a=list()
for j in range(1,int(n**0.5)+1):
    if n%j==0:
        a.append(j)
        if j*j!=n:
            a.append(n//j)
a.sort()
i=len(a)
while i>1:
    if n+1<=a[i-1]+n<=n+k:
        print(n+a[i-1])
        break
    i-=1
if i==1:
    print(n+1)