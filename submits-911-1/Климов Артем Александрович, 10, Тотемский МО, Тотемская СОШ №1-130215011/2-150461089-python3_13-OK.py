n=int(input())


def g(n):
    b=[]
    for i in range(n):
        if i==0:
            b.append(1)
        elif i==1:
            b.append(2)
        elif i==2:
            b.append(3)
        else:
            b.append(3*(2**(i-2)))
    return b

a=[]
a=g(n)


b=sum(a)
flag=True
for i in range(len(a)):
    if b%a[i]!=0:
        flag=False
if flag:
    print(b)
    print(*a)
else:
    print(-1)