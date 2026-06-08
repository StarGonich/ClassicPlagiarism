n=int(input())
k=int(input())
mi=21111111111111111111111111111111111111
for i in range(1,n+k+1):
    if i>=n+1 and i<=n+k:
		p=i
        for k in range(1,1000):
            if k%n==0 and k%i==0:
                if k<mi:
                    p=i
                    mi=k
print(p)
                