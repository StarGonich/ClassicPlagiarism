n=int(input())
k=int(input())
p=0
a=0
answer=None
count=None
for i in range(1,n+k-1):
    count=n+i
    for p in range(1,n+k):
     if count%p==0 and count%n==0:
         answer=p; print(i,p)
print(answer)        