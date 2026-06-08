h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
k=0
for h in range(h1,h2+1):
    for m in range(m1,m2+1):
        f=str(h)
        d=str(m)
        if m<10:
            d='0'+str(d)
        if f==d or f==d[::-1]:
            k+=1
        if int(f[0])+1==int(f[1]) and int(f[1])+1==int(d[0]) and int(d[0])+1==int(d[1]):
            k+=1                
print(k)                                              