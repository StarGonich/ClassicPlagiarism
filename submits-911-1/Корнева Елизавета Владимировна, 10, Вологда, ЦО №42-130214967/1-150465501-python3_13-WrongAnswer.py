h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p=0
h=0
if m1>m2:
    h1+=1
    m1-=m2
if h1>h2:
    hk=h1+h2%24
for m in range (m1,m2+1):
    mk=m%10
    mk2=m//10
    for h in range (h,h1+1):
        hk=h%10
        hk2=h//10
        if h==m:
            p+p+1
        if (hk==mk and hk2==mk2) or (hk==mk and hk2==mk2):
            p+=1
print (p)