n=int(input())
k=int(input())
l=n+1
r=k+n
a=[]

for i in range(l,r+1):
    a.append(i)
b=[]
count=1

for i in range(2,int(n**0.5)+1):
    while True:
        if n%i==0:
            b.append(i)
            n=n//i
        else:
            break
if n!=1:
    b.append(n)
n=l-1




for i in range(len(a)):
    x=n
    y=a[i]
    x1=x
    y1=y
    z=1
    for j in range(len(b)):
        if x%b[j]==0 and y%b[j]==0:
            x1=x1//b[j]
            y1=y1//b[j]
            z=z*b[j]
    
    w=x1*y1*z
    if i==0:
        count=[w,y1]
    else:
        if w<count[0]:
            count[0]=w
            count[1]=y1*z
    
print(count[1])