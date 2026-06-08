h = int(input())
m = int(input())
h2 = int(input())
m2 = int(input())
k=0
c=0
while h!=h2:
    if m==60:
        h+=1
        m==0
    if h==24:
        h=0
        m = 0
    m0 = m%10
    m9 = m//10
    h0 = h%10
    h9 = h//10
    if h==m:
        k+=1
    elif m0==h9 and h0==m9:
        k+=1
    elif h9+1==h0 and h0+1==m9 and m9+1==m0:
        k+=1
    m+=1
    c+=1
print(k)