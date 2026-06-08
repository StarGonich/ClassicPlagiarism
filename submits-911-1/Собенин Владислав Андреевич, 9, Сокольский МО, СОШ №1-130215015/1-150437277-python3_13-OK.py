def create_time(h,m):
    r=''
    if h<10:
        r+='0'
    r+=str(h)
    r+=':'
    if m<10:
        r+='0'
    r+=str(m)
    return r


def kras(t):
    usl3=int(t[0])-int(t[1])==-1 and int(t[1])-int(t[3])==-1 and int(t[3])-int(t[4])==-1
    return usl3 or t[0:2]==t[3:] or t[0:2]==t[-1:-3:-1]


h1,m1,h2,m2=int(input()),int(input()),int(input()),int(input())
h,m=h1,m1
ans=0


while h!=h2 or m!=m2:
    t=create_time(h,m)
    if kras(t):
        ans+=1
    m+=1
    if m==60:
        h,m=h+1,0
        if h==24:
            h=0
t=create_time(h,m)
if kras(t):
    ans+=1


print(ans)
