n = int(input())
t = int(input())
b = []
g = 10^9
for i in range(n):
    t1, t2 = map(int, input().split())
    for j in range(t2 - t1 + 1):
        b = b + [t1 + j]
for j in range(b[-1] - 3600):
    d = 0
    for z in range(3600):
        if b.count(z + j) == 1:
            d = d + 1
    if d >= t:
        g = j
        break
if g = 10^9:
    print(-1)
else:
    print(g)