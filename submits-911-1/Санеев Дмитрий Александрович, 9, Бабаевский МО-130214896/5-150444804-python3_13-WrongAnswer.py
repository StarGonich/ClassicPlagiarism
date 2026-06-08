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
                else:
                    new_grid[i][j] = 0
    return new_grid

def grids_equal(g1, g2):
    return all(g1[i][j] == g2[i][j] for i in range(len(g1)) for j in range(len(g1[0])))

import sys
input = sys.stdin.read
data = input().split()

k = int(data[0])
n = int(data[1])
m = int(data[2])

configs = []

pos = 3
for _ in range(k):
    grid = []
    for _ in range(n):
        row = list(map(int, data[pos:pos+m]))
        pos += m
        grid.append(row)
    configs.append(grid)

possible_prev = [[] for _ in range(k)]

for i in range(k):
    for j in range(k):
        if i != j:
            if grids_equal(next_state(configs[j]), configs[i]):
                possible_prev[i].append(j)

start_indices = [i for i in range(k) if len(possible_prev[i]) == 0]

start_idx = start_indices[0]

order = []
visited = [False] * k
current = start_idx

while True:
    order.append(current + 1)
    next_conf = None
    for i in range(k):
        if not (i in order): 
            if grids_equal(next_state(configs[current]), configs[i]):
                next_conf = i
                break
    if next_conf is None:
        break
    current = next_conf

print(' '.join(map(str, order)))