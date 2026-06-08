n=int(input())
t=int(input())
b=[0]*150000
a=[0]*150000
fl=0
l1=3600
for i in range(n):
    if fl==0:
        l,r=map(int,input().split())
        l+=3600
        r+=3600
        for j in range (l1,l+1):
            a[j]=a[j-1]-b[j-3600]
        l1=r+1
        for j in range(l+1,r+1):
            b[j]=1
            a[j]=a[j-1]-b[j-3600]+b[j]
            if a[j]>t:
                fl=1
                print(j-7200)
                break
if fl==0:
    print(-1)


        
