def nok(s, q):
    d = s * q
    while s!=0 and q!=0:
        if s>q:
            s%=q
        else:
            q%=s
    return d//(s+q)
n=int(input())
k=int(input())
b=[]
a=[]
for p in range (n+1,n+k+1):
    a.append(nok(p,n))
    b.append(p)
print(b[a.index(min(a))])