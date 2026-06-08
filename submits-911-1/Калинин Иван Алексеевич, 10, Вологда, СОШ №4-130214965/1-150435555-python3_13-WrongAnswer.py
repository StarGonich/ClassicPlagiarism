h1 = int(input())
m1 = int(input())
h2 = int(input())
m2 = int(input())
k=0
for h in range(h1, h2+1):
    for m in range(m1, m2+1):
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
print(k)
