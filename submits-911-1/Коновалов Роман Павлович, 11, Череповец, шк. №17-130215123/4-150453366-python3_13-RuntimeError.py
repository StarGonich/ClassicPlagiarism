n = int(input())
k = int(input())
def NOK(n, p):
    for i in range(1, 100000):
        if i % p == 0 and i % n == 0:
            return i
    return 1000000000
t = []
pp = []
for p in range(2, 100):
    m = NOK(n, p)
    if p >= n + 1 and p <= n + k:
        t.append(m)
        pp.append(p)
print(pp[t.index(min(t))])