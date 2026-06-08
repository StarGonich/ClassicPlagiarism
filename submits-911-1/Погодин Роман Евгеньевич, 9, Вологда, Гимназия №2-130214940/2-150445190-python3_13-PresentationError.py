a=int(input())
b=0
k=0
while b<a:
    b+=1
    if a%b==0:
        k+=1
print(k-1)
for i in range(1,a,+1):
    if a%i==0:
        print(i,end=' ')