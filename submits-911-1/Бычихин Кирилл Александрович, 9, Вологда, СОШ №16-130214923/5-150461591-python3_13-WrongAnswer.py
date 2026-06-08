k = int(input())
n = int(input())
m = int(input())
b = []
for _ in range(k):
    t = []
    for _ in range(n):
        r = list(map(int, input().split())) #воод чисел через пробел
        t.append(r)
    b.append(t)
nx = [None] * k
pv = [None] * k
def ng(bo): # - старый neigbors.py
    nb = [[0 for _ in range(m)] for _ in range(n)]
    for i in range(n):
        for j in range(m):
            cn = 0
            for x in range(max(0, i - 1), min(n, i + 2)):
                for y in range(max(0, j - 1), min(m, j + 2)):
                    if (x, y) != (i, j):
                        cn += bo[x][y]
            if (bo[i][j] == 1):
                if cn == 2 or cn == 3:
                    nb[i][j] = 1
                else:
                    nb[i][j] = 0
            else:
                if (cn == 3):
                    nb[i][j] = 1
                else:
                    nb[i][j] = 0
    return nb
def ae(b1, b2): # test.py
    for i in range(n):
        for j in range(m):
            if b1[i][j] != b2[i][j]:
                return False
    return True

for i in range(k):# main.py
    for j in range(k):
        if (i != j):
            if ae(ng(b[i]), b[j]):
                nx[i] = j
            if ae(ng(b[j]), b[i]):
                pv[i] = j
si = -1
for i in range(k):
    is_s = True
    for j in range(k):
        if pv[i] == j:
            is_s = False
            break
    if (is_s):
        si = i
        break
res = []
ci = si
while ci is not None: # старый print result.py
    res.append(ci + 1)
    nf = False
    for i in range(k):
        if (pv[ci] == i):
            nf = True
            break
    ci = nx[ci]
print(*res)
