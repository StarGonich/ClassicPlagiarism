n=int(input())
k=int(input())
p=0
if n>k:
    for i in range(n+k-n):
        p=n+1
        if p%2==0 and n%2==0:
            print(p)
        if p%3==0 and n%3==0:
            print(p)
if n<k:
    for i in range(n+k-k):
        p=n+1
        if p%2==0 and k%2==0:
            print(p)
        if p%3==0 and k%3==0:
            print(p)
print(p)
