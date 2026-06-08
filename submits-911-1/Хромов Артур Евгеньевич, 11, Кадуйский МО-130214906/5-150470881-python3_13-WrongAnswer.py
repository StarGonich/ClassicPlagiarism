k = int(input())
n = int(input())
m = int(input())

c = []
for x in range(k):
    grid = []
    for y in range(n):
        row = list(map(int, input().split()))
        grid.append(row)
    c.append(grid)

def nexts(grid):
    new_grid = [[0] * m for _ in range(n)]
    dr = [-1, -1, -1, 0, 0, 1, 1, 1]
    dc = [-1, 0, 1, -1, 1, -1, 0, 1]
    for r in range(n):
        for c in range(m):
            live = 0
            for d in range(8):
                nr, nc = r + dr[d], c + dc[d]
                if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 1:
                    live += 1
            if grid[r][c] == 1:
                if live in (2, 3):
                    new_grid[r][c] = 1
                else:
                    new_grid[r][c] = 0
            else:
                if live == 3:
                    new_grid[r][c] = 1
                else:
                    new_grid[r][c] = 0
    return new_grid

def equal(a, b):
    for i in range(n):
        for j in range(m):
            if a[i][j] != b[i][j]:
                return False
    return True

next_map = [-1] * k
prev_count = [0] * k

for i in range(k):
    nxt = nexts(c[i])
    for j in range(k):
        if equal(nxt, c[j]):
            next_map[i] = j
            prev_count[j] += 1

start = -1
for i in range(k):
    if prev_count[i] == 0:
        start = i
        break

order = []
cur = start
for x in range(k):
    order.append(cur + 1)
    cur = next_map[cur]

for c in order:
    print(c, end = ' ')