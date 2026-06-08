a = int(input())
b = []
c = 0
for i in range(1, 36 * a):
    b.clear()
    c = 0
    for j in range(1, i):
        if i % j == 0:
            b.append(j)
            c += j
    if c == i:
        if len(b) == a:
            break
    else:
        continue
if not(len(b) == a):
    print(-1)
else:
    print(c)
    print(b)