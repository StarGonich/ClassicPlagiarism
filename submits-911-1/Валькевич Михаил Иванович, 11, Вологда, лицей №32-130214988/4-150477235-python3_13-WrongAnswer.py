n=int(input())
k=int(input())
mi=21111111111111111111111111111111111111
p=0
for i in range(1,n+k+1):
    if i>=n+1 and i<=n+k:
        for k in range(1,1000):
            if k%n==0 and k%i==0:
                if k<mi:
                    p=i
                    mi=k
        l=i
if p==0:
    p=l
        
print(p)
          