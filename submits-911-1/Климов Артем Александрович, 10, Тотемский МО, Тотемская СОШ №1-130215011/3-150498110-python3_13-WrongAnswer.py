n=int(input())
t=int(input())
a=[]
for i in range(n):
    a.append([int(i) for i in input().split()])

l=0
r=0

l1=0
r1=3600

count=0
flag=True
for i in range(401):
    l1=i
    r1=i+3600
    count=0
    for j in range(n):
        if a[j][0]>=l1 and a[j][1]<=r1:
            count+=(a[j][1]-a[j][0])
        else:
            if a[j][0]>=l1:
                count+=(r1-a[j][0])
                
            elif a[j][1]<=r1:
                count+=(a[j][1]-l1)
                
            else:
                count+=0
                
    if count>t:
        flag=False
        print(l1)
if flag:
    print(-1)