k = int(input())
n=int(input())
m=int(input())
a=[0] * n
l=0
for i in range(k):
    for j in range(n):
        a[j]=list(map(int,input().split()))
        if a[j].count(0)==m:
            l+=1
    if l==n:
        if k==0:
            print('2 1')
            l=0
        else:
            print('1 2')
            l=0
