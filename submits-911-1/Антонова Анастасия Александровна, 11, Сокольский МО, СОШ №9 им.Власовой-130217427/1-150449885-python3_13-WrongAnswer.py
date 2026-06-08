h1= int(input())
m1= int(input())
h2= int(input())
m2= int(input())
n=0
if 0<=h1 and 0<=m1 and h2<=23 and m2<=59:
    for a in range(h1,h2+1):
        for b1 in range(m1,61):
            if a==b1:
                n=n+1
if 0<=h1 and 0<=m1 and h2<=23 and m2<=59:
    for a in range(h1+1,h2+1):
        for b2 in range(0,m2+1):
            if a==b2:
                n=n+1
print(n)