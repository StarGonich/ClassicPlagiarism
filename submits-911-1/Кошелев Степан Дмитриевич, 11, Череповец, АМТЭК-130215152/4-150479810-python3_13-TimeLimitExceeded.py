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
c=n+k+1
v=n+1
b=[]
a=[]
while v!=c:
    a.append(nok(v,n))
    b.append(v)
    v+=1
a.append(nok(v,n))
b.append(v)
print(b[a.index(min(a))])