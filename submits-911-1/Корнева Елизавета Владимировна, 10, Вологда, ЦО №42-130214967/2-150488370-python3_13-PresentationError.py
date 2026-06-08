n=int(input())
m=0
p=0
for i in range (1,100):
    if i%i==0:
        m+=i
        p+=1
    if p==n:
        break
print (m)
if n==1:
    print (1)
elif n==2:
    print (1,i)
elif n==3:
    print (1,i-1,i)