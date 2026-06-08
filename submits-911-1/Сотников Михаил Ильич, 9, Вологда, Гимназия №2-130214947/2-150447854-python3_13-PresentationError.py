a=int(input())
b=0
k=0
a=a*2
print(a)
for i in range(a-1,0,-1):
    if a%i==0:
        print(i, end=' ')