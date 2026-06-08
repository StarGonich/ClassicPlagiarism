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



count=0
count1=0
for i in range(len(a)):
    x=n
    y=a[i]
    x1=x
    y1=y
    z=1
    
    m=[]
    for j in range(len(b)):
        if y1%b[j]==0:
            y1=y1//b[j]
            m.append(b[j])
    
    m1=1
    for i in range(len(m)):
        m1=m1*m[i]
    
    if count<m1:
        count=m1
        count1=y1*m1

    
    
print(count1)
