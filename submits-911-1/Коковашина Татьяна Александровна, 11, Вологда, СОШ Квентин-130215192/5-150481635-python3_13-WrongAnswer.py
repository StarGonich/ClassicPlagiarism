k = int(input())
n = int(input())
m = int(input())

mebe = []
for _ in range(k):
    g = []
    for _ in range(n):
        g.append(list(map(int, input().split())))
    mebe.append(g)

tuples = [tuple(tuple(row) for row in g) for g in mebe]

sled = [-1] * k

for i in range(k):
    cur = mebe[i]
    nxt = [[0] * m for _ in range(n)]
    for x in range(n):
        for y in range(m):
            s = 0
            for dx in (-1, 0, 1):
                for dy in (-1, 0, 1):
                    if dx == dy == 0:
                        continue
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m:
                        s += cur[nx][ny]
            if cur[x][y]:
                nxt[x][y] = 1 if s in (2, 3) else 0
            else:
                nxt[x][y] = 1 if s == 3 else 0
    nxt_t = tuple(tuple(row) for row in nxt)
    for j in range(k):
        if tuples[j] == nxt_t:
            sled[i] = j
            break

indeg = [0] * k
for i in range(k):
    j = sled[i]
    if j != -1 and j != i:
        indeg[j] += 1

start = 0
for i in range(k):
    if indeg[i] == 0:
        start = i
        break

res = []
vis = [False] * k
cur = start
while cur != -1 and not vis[cur]:
    res.append(cur + 1)
    vis[cur] = True
    nxt = sled[cur]
    if nxt == cur:
        break
    cur = nxt

print(' '.join(map(str, res)))