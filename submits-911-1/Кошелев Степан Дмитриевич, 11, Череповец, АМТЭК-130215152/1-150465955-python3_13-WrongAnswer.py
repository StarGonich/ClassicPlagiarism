h1=int(input())
m1=int(input())
h2=int(input())
m2=int(input())
k=0
while m1!=m2 or h1!=h2:
    m1+=1
    if m1==60:
        h1+=1
        m1-=60
    if h1==24:
        h1=0
    f=str(h1)
    d=str(m1)
    if h1<10:
        f='0'+str(f)
    if m1<10:
        d='0'+str(d)
    if f==d or f==d[::-1] or int(f[0])+1==int(f[1]) and int(f[1])+1==int(d[0]) and int(d[0])+1==int(d[1]):
        k+=1 
print(k)