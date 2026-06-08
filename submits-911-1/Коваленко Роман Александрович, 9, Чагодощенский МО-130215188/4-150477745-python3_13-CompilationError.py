n = int(input())
k = int(input())

p = n + 1

a = 0

m = (n + k) * (n + k + 1)
g = 0

while p <= n + k:
    c = n
    d = p
    for i in range(p - 1):
        if c < d:
            d -= c
        elif c > d:
            c -= d
    a = n * (p // c)
    if a < m:
        m = a
        g = p
	p += 1
print(g)