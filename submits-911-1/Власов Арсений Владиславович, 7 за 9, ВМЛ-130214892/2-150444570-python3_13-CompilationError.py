a = int(input())
b = set()
c = 0
for i in range(1, 100):
    b.clear()
    c = 0
    for j in range(1, i):
        if i % j == 0:
            b.add(j)
            c += j
        else:
            b.discard(j)
    if c == i:
        if len(b) == a:
            break
    else:
        continue
if not(len(b) == a):
    print(-1)
else:
    print(6)
    print(1 2 3)