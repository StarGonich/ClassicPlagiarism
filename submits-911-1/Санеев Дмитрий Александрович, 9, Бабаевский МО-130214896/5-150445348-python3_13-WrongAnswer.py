def get_neighbors(n, m, grid, i, j):
    directions = [(-1, -1), (-1, 0), (-1, 1),
                  (0, -1),           (0, 1),
                  (1, -1),  (1, 0),  (1, 1)]
    count = 0
    for dx, dy in directions:
        x, y = i + dx, j + dy
        if 0 <= x < n and 0 <= y < m:
            if grid[x][y] == 1:
                count += 1
    return count

def next_state(grid):
    n = len(grid)
    m = len(grid[0])
    new_grid = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            neighbors = get_neighbors(n, m, grid, i, j)
            if grid[i][j] == 1:
                if neighbors == 2 or neighbors == 3:
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = 0
            else:
                if neighbors == 3:
                    new_grid[i][j] = 1
    return new_grid

def grids_equal(g1, g2):
    return all(g1[i][j] == g2[i][j] for i in range(len(g1)) for j in range(len(g1[0])))

import sys
input = sys.stdin.read
data = input().split()

k = int(data[0])
n = int(data[1])
m = int(data[2])

pos = 3
configs = []

for _ in range(k):
    grid = []
    for _ in range(n):
        row = list(map(int, data[pos:pos+m]))
        pos += m
        grid.append(row)
    configs.append(grid)

adj = [[] for _ in range(k)]
in_degree = [0]*k

for i in range(k):
    for j in range(k):
        if i != j:
            if grids_equal(next_state(configs[j]), configs[i]):
                adj[j].append(i)
                in_degree[i] += 1

start_nodes = [i for i in range(k) if in_degree[i] == 0]
start_idx = start_nodes[0]

order = []
visited = [False]*k
current = start_idx
order.append(current + 1)

while True:
    next_idx = None
    for v in adj[current]:
        if not (v in order):
            next_idx = v
            break
    if next_idx is None:
        break
    order.append(next_idx + 1)
    current = next_idx

print(' '.join(map(str, order)))