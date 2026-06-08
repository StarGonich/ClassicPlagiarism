a = int(input())
b = set()
c = 0
d = 0
for i in range(1, 100):
    b.clear()
    c = 0
    d = 0
    for j in range(1, i):
        if i % j == 0:
            b.add(j)
            c += j
            d += 1
        else:
            b.discard(j)
    if c == i:
        if d == a:
            break
    else:
        continue
print(c)
print(b)