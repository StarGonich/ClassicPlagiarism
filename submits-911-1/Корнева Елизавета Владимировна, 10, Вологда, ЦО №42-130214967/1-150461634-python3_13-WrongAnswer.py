h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p=0
mmm1=h1%10
mmh1=h1//10
mmm2=h2%10
mmh2=h2//10
if m1>m2:
    h1+=1
    m1-=m2
if h1>h2:
    hk=h1+h2%24
for m in range (m1,m2+1):
    mk=m%10
    mk2=m//10
    if h1==m:
        p+=1
    if (mmm1==mk and mmh1==mk2) or (mmm2==mk and mmh2==mk2):
        p+=1
print (p)