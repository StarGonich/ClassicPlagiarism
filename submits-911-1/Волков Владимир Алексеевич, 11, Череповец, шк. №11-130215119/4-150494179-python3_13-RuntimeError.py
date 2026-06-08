n = int(input())
k = int(input())
p = []
min_nok = 1
cp = 0
def nod(a, b):
    m = []
    for i in range(2, min(a,b) + 1):
        if a % i == 0 and b % i == 0:
            m.append(i)
    if len(m) > 0:
        return max(m)
    else:
        return 1
def nok(a, b):
    return abs(a * b) // nod(a, b)

for i in range(1, 10000):
    if i >= n + 1 and i <= n + k:
        p.append(i)
mn = []
mi = []
for i in p:
    mn.append(nok(n, i))
    mi.append(i)
v = mn.index(min(mn))
cp = mi[v]
print(cp)