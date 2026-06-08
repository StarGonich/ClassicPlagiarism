n = int(input())
k = int(input())
r = n + 1
m = n * (n + 1)
for p in range(n + 1, n + k + 1):
    a, b = n, p
    while b:
        a, b = b, a % b
    k = a
    t = n * p // k
    if t < m:
        m + t
        r + p
print(r)