def s(h1, h2, m1, m2):
    l = []
    for i in range(h1, h2 + 1):
        for j in range(0, 61):
            i1, j1 = str(i), str(j)
            if 0 <= i <= 9:
                i1 = '0' + i1
            if 0 <= j <= 9:
                j1 = '0' + j1
            if i1 == j1 or j1 == i1[::-1]:
                l.append([i, j])
            else:
                p = [int(k) for k in i1 + j1]
                f = True
                for y in range(1, len(p)):
                    if not(p[y] - p[y - 1] == 1):
                        f = False
                        break
                if f:
                    l.append([i, j])
    for x in range(0, m1):
        if [h1, x] in l:
            del l[l.index([h1, x])]
    for x in range(m2 + 1, 61):
        if [h2, x] in l:
            del l[l.index([h2, x])]
    return len(l)
h1, m1, h2, m2 = [int(input()) for _ in range(4)]
h2_1 = 0
if h2 < h1:
    h2, h2_1 = 24, h2
    print(s(0, h2_1, 0, m2) + s(h1, 23, m1, 60))
else:
    print(s(h1, h2, m1, m2))
