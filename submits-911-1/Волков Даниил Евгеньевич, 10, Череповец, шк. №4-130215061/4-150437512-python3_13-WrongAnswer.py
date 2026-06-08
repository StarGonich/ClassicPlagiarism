n=int(input())
k=int(input())
p=0
for i in range(1,n*k):
    print(i)
    if i%n==0 and i%k==0:
            p=i;
print(p)