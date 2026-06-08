n=int(input())
t=int(input())
a=[0]*10000000
for i in range (n):
    b,e=map(int,input().split())
    for j in range(b,e+1):
        a[j]=1
i=0
while i<=e-3600:
    c=0
    c=a[i:i+3599].count(1)
    if c>t:
        print(i)
        break
    i+=1
