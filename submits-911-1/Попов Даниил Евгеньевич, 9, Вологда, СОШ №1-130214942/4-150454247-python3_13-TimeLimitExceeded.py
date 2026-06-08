n = int(input())
k = int(input())

def NOK(a,b):
    for i in range(min(a,b),a*b+1):
        if i % a == 0 and i % b == 0:
            return i
            break
        
noks = list()
ps = list()

for p in range(n+1, n+k+1):
    noks.append(NOK(n, p))
    ps.append(p)
    
noksm = min(noks)
for i in range(len(noks)):
    if noks[i] == noksm:
        print(ps[i])
