k = int(input())
n = int(input())
m = int(input())

configs = []
for _ in range(k):
    grid = []
    for i in range(n):
        row = list(map(int, input().split()))
        grid.append(row)
    configs.append(grid)

def next_step(grid):
    new_grid = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            neighbors = 0
            for di in (-1,0,1):
                for dj in (-1,0,1):
                    if di == 0 and dj == 0:
                        continue
                    ni, nj = i+di, j+dj
                    if 0 <= ni < n and 0 <= nj < m:
                        neighbors += grid[ni][nj]
            if grid[i][j] == 1:
                new_grid[i][j] = 1 if neighbors in [2,3] else 0
            else:
                new_grid[i][j] = 1 if neighbors == 3 else 0
    return new_grid

order = []
used = [False]*k

for step in range(k):
    for i in range(k):
        if used[i]:
            continue
        next_g = next_step(configs[i])
        found = False
        for j in range(k):
            if i != j and not used[j] and next_g == configs[j]:
                found = True
                break
        if not found:
            order.append(i+1)
            used[i] = True
            break

print(' '.join(map(str, order)))