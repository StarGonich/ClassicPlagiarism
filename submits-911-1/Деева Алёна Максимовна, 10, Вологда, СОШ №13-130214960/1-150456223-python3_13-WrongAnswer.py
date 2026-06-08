h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
i = m1
n=0
a=0
b=0
c=m2
if h2<h1:
    h2=h2+24
if h1!=h2:
    c=60
while (i<c or i == c) and (h1<h2 or h1==h2):
    a=i%10*10+i//10
    if h1 == i or h1==a or i==h1/10 or (i==(h1//10+2)*10+(h1%10)+2 and h1//10+2 < h1%10+2):
        n=n+1
    
    i=i+1
    if i==60 and h1!=h2:
        i=0
        h1=h1+1
    if h1==24:
        h1 = 0
        h2 = h2 - 24
    if h1==h2:
        c=m2
print (n)