n = int(input())
k = int(input())

def NOK(a,b):
    for i in range(a,a*b+1):
        if i % a == 0 and i % b == 0:
            return i
            break
        
noks = list()
ps = list()

for p in range(n+1, n+k+1):
    nok = NOK(n, p)
    noks.append(nok)
    ps.append(p)
    if nok < min(noks):
        noks.append(nok)
        ps.append(p)

m = noks.index(min(noks))
print(ps[m])
