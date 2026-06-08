def nok(a, b):
    r = int(min(a, b))
    while r % a != 0 or r % b != 0:
        r += 1
    return r
n = int(input())
k = int(input())
mp=0
m = 100000000000
for p in range(n + 1, n + k + 1):
    if nok(n, p) < m:
        m = nok(n, p)
        mp = p
print(mp)
