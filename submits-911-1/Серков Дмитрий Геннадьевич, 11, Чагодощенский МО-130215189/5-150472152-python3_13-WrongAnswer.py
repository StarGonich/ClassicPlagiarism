
k = int(input())
n = int(input())
m = int(input())

gri = []
for _ in range(k):
    temp = [tuple(map(int, input().split())) for _ in range(n)]
    gri.append(tuple(temp))

def nxt(a):
    b = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            c = 0
            for x in (-1,0,1):
                for y in (-1,0,1):
                    if x == 0 and y == 0:
                        continue
                    ni, nj = i+x, j+y
                    if 0<=ni<n and 0<=nj<m:
                        c += a[ni][nj]
            if a[i][j] == 1 and (c==2 or c==3):
                b[i][j] = 1
            elif a[i][j] == 0 and c==3:
                b[i][j] = 1
    return tuple(tuple(row) for row in b)

gra = [[] for _ in range(k)]
for i in range(k):
    t = nxt(gri[i])
    for j in range(k):
        if i!=j and t==gri[j]:
            gra[i].append(j)

deg = [0]*k
for l in gra:
    for v in l:
        deg[v] += 1

st = deg.index(0)

res = []
cur = st
while True:
    res.append(cur+1)
    if not gra[cur]:
        break
    cur = gra[cur][0]

print(*res)