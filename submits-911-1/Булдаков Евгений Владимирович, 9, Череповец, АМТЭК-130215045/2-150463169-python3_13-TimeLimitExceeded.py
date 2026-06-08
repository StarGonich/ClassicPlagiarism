n=int(input())
s=0
j=0
sum=0
for i in range(1,1000000001):
    j=j+1
    if i//j==0:
        s=s+1
        sum=sum+j
print(sum)
        
