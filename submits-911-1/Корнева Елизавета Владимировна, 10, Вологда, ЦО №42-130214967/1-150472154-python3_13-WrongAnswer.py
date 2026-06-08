h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
p=0
hp=h2
mp=m2
if m1>mp:
    h1+=1
    mp=m1-mp
if h1>hp:
    hp=h1-hp
for m in range (m1,mp+1):
    mk=m%10
    mk2=m//10
    for h in range (h1,hp+1):
        hk=h%10
        hk2=h//10
        if h==m:
            p=p+1
        if (hk==mk and hk2==mk2) or (hk==mk and hk2==mk2):
            p+=1
        if (mk-1==mk2) and (mk2-1==hk) and (hk-1==hk2):
            p+=1
print (p)