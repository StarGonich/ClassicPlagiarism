def nod(a,b):
    while a!=b:
        if a>b:
            a-=b
        if b>a:
            b-=a
    return a


def nok(a,b):
    return a*b/nod(a,b)


n,k=int(input()),int(input())
noks=[]


for p in range(n+1,n+k+1):
    noks.append(nok(p,n))


print(noks.index(min(noks))+n+1)
