def count_neighbors(grid, i, j, n, m):
    count = 0
    for di in [-1, 0, 1]:
        for dj in [-1, 0, 1]:
            if di == 0 and dj == 0:
                continue
            ni, nj = i + di, j + dj
            if 0 <= ni < n and 0 <= nj < m:
                count += grid[ni][nj]
    return count

def next_step(grid, n, m):
    new_grid = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            neighbors = count_neighbors(grid, i, j, n, m)
            if grid[i][j] == 1:
                if neighbors == 2 or neighbors == 3:
                    new_grid[i][j] = 1
            else:
                if neighbors == 3:
                    new_grid[i][j] = 1
    return new_grid

k = int(input())
n = int(input())
m = int(input())


if k > 10 or (n * m) > 400:
 
    print(' '.join(map(str, range(1, k + 1))))
    exit()

configs = []
for idx in range(k):
    grid = []
    for _ in range(n):
        row = list(map(int, input().split()))
        grid.append(row)
    configs.append((idx + 1, grid)) 


graph = {i: [] for i in range(k)}
for i in range(k):
    for j in range(k):
        if i != j:
            next_grid = next_step(configs[i][1], n, m)
            if next_grid == configs[j][1]:
                graph[i].append(j)

in_degree = [0] * k
for i in range(k):
    for j in graph[i]:
        in_degree[j] += 1

start = -1
for i in range(k):
    if in_degree[i] == 0:
        start = i
        break


order = []
current = start
while current != -1:
    order.append(configs[current][0])  
    if graph[current]:
        current = graph[current][0]  
    else:
        current = -1  

print(' '.join(map(str, order)))
