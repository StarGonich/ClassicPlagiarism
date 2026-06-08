def nok(n, p):
    mx = p
    while True:
        if mx % n == 0 and mx % p == 0:
            break
        if (mx + n) % n == 0 and (mx + n) % p == 0:
            mx += n
            break
        if (mx + p) % n == 0 and (mx + p) % p == 0:
            mx += p
            break
        mx += p
    return mx
n, k = int(input()), int(input())
mn = nok(n, n + 1)
res = n + 1
for p in range(n + 2, n + k + 1):
    a = nok(n, p)
    if a < mn:
        mn = a
        res = p
print(res)