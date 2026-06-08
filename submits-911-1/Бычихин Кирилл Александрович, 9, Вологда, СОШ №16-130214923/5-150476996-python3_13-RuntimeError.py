def g(n, m, f):
    nf = [[0] * m for _ in range(n)]
    d = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    
    for i in range(n):
        for j in range(m):
            a = 0
            for dx, dy in d:
                ni, nj = i + dx, j + dy
                if 0 <= ni < n and 0 <= nj < m:
                    a += f[ni][nj]
            if f[i][j] == 1:
                if a in [2, 3]:
                    nf[i][j] = 1
            else:
                if a == 3:
                    nf[i][j] = 1
                    
    return nf

def c(f1, f2):
    return f1 == f2

def fo(k, n, m, cfg):
    s = {tuple(map(tuple, c)): i + 1 for i, c in enumerate(cfg)}
    
    o = []
    cur = cfg[0]
    
    for _ in range(k):
        o.append(s[tuple(map(tuple, cur))])
        cur = g(n, m, cur)
        if tuple(map(tuple, cur)) in s:
            cur = cfg[s[tuple(map(tuple, cur)) - 1]]
        else:
            break

    return o

k = int(input())
n = int(input())
m = int(input())
cfg = []

for _ in range(k):
    c = [list(map(int, input().split())) for _ in range(n)]
    cfg.append(c)

r = fo(k, n, m, cfg)

print(" ".join(map(str, r)))