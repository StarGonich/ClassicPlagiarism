def read_input():
    k = int(input())
    n = int(input())
    m = int(input())
    configs = []
    for _ in range(k):
        grid = [list(map(int, input().split())) for _ in range(n)]
        configs.append(grid)
    return k, n, m, configs

def serialize(grid):
    return ''.join(''.join(str(cell) for cell in row) for row in grid)

def neighbors(grid, i, j, n, m):
    deltas = [(-1, -1), (-1, 0), (-1, 1),
              (0, -1),           (0, 1),
              (1, -1),  (1, 0),  (1, 1)]
    count = 0
    for di, dj in deltas:
        ni, nj = i + di, j + dj
        if (0<=ni<n and 0<=nj<m):
            count+=grid[ni][nj]
    return count

def next_state(grid, n, m):
    new_grid = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            alive_neighbors = neighbors(grid, i, j, n, m)
            if(grid[i][j] == 1):
                if (alive_neighbors in [2, 3]):
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = 0
            else:
                if (alive_neighbors == 3):
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = 0
    return new_grid

def main():
    k, n, m, configs = read_input()
    serialized_configs = [serialize(cfg) for cfg in configs]

    index_map = {sc: i for i, sc in enumerate(serialized_configs)}
    predecessors = [-1] * k

    for i in range(k):
        for j in range(k):
            if (i != j):
                if next_state(configs[j], n, m) == configs[i]:
                    predecessors[i] = j
                    break

    start_index = predecessors.index(-1)
    sequence = []
    current = start_index
    while (current != -1):
        sequence.append(current + 1)
        current = predecessors[current]
    sequence.reverse()
	
    print(' '.join(map(str, sequence)))

main()