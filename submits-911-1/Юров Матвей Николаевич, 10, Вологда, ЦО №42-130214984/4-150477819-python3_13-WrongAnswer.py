n=int(input())
k=int(input())
for p in range(n+1,n+k+1):
    if n%p==0 and p!=n+1:
        print(p)
        break;
    