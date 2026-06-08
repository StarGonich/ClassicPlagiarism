n = int(input())
b = []
for i in range(10^9):
    a = i + 1
    for j in range(a // 2):
        if a % (j + 1) == 0:
            b = b + [j + 1]
    g = sum(b)
    if g == a:
        break
    else:
        t = g - a
        if b.count(t) == 1:
            b = b.remove(t)
            break
print(a)
print(' '.join(str(el) for el in b))