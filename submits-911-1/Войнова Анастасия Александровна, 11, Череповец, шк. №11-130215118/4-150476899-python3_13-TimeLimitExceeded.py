def nok(n, p):
    for i in range(p, n * p + 1):
        if i % n == 0 and i % p == 0:
            return i
n, k = int(input()), int(input())
mn = nok(n, n + 1)
res = n + 1
for p in range(n + 2, n + k + 1):
    a = nok(n, p)
    if a < mn:
        mn = a
        res = p
print(res)