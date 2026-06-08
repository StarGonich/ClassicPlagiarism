ans=10000000
a=0
n=int(input())
k=int(input())
for p in range(n+k,n+2,-1):
    print(p)
    flag = False
    for i in range(1,n*p//2):
        if i%n==0 and i%p==0:
            if ans>i:
                flag=True
                break;
    if flag:
        a=p
        break
print(a)
    