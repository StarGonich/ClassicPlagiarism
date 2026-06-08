h1,m1,h2,m2=int(input()),int(input()),int(input()),int(input())
n=0
while h1<=h2 and m1<=m2:
    r1=h1//10
    r2=h1%10
    r3=m1//10
    r4=m1%10
    if m1==60:
        h1+=1
        m1=0
    if h1==m1 or str(h1)==(str(r4)+str(r3)) or ((r2==r1+1) and(r3==r1+2)and(r4==r1+3)):
        n+=1
    m1+=1
print(n)
    
    