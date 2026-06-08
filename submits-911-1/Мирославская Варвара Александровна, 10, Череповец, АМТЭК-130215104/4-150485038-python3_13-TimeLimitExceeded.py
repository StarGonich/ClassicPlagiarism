def nod(x,y):
    a=max(x,y)
    b=x+y-a
    while a%b!=0:
        x=a%b
        a=b
        b=x
    return b
n=int(input())
k=int(input())
min=999999999
for i in range(n+1,n+k+1):
    x=(n*i)//nod(i,n)
    if x<min:
        min=x
        p=i
print(p)