ans=10000000000
a=[]
n=int(input())
k=int(input())
for p in range(n+k,n+2,-1):
    for i in range(1,n*p):
        if i%n==0 and i%p==0:
            if i<ans:
                a.append(p)
                ans=i
print(min(a))