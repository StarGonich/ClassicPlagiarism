ans=10000000000
a=[]
n=int(input())
k=int(input())
for p in range(n+k+1,n+2,-1):
    for i in range(1,n*p+1):
        if i%n==0 and i%p==0:
            if i<ans:
                a.append(p)
                ans=i
print(min(a))