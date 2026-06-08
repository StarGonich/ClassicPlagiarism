h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
i = m1
n=0
a=0
b=0
while i<m2 or i == m2:
    if i>9 and i%10!=0:
        a=i%10*10+i//10
    if h1 == i or h1==a or i==h1/10 or (h1//10 == h1%10-1 and h1//10 == m1//10 - 2 and h1//10 == m1%10 - 3):
        n=n+1
print (n)