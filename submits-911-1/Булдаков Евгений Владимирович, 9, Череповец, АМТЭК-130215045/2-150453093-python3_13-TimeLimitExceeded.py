n=int(input())
s=0
while s!=n:
    for i in range(1,1000000001):
        for j in range(1,i):
            if i//j==0:
                s=s+1
print(i)
