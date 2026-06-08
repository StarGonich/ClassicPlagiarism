def nod(a, b):
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a
    return a
n = int(input())
nn = n
k = int(input())
pmin = 0
minw = 99999999999999999999
for i in range(n + 1, n + k + 1):
    ii = i
    q = nod(ii, nn)
    while q != 1:
        ii /= q
        nn /= q
        q = nod(ii, nn)
    w = nn * i
    if w < minw:
        minw = w
        pmin = i
    nn = n
print(pmin)