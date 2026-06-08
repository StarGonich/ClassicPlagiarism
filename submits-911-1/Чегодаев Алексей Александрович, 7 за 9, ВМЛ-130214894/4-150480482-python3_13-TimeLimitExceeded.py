n = int(input())
k = int(input())
m = 100000000000
p = 0
for i in range(n + 1, n + k + 1):
    p2 = i
    n2 = n
    while(p2 > 0 and n2 > 0):
        if p2 > n2:
            p2 -= p2 // n2 * n2
        else:
            n2 -= n2 // p2 * p2
    p2 = max(p2, n2)
    nok = i * n // p2
    if nok < m:
        p = i
        m = nok
print(p)