def solve():
    k = int(input())
    n = int(input())
    m = int(input())

    grids = []
    for _ in range(k):
        grid = []
        for _ in range(n):
            row = list(map(int, input().split()))
            grid.append(row)
        grids.append(grid)

    def next_generation(grid):
        new_grid = [[0] * m for _ in range(n)]
        for i in range(n):
            for j in range(m):
                live_neighbors = 0
                for x in range(max(0, i - 1), min(n, i + 2)):
                    for y in range(max(0, j - 1), min(m, j + 2)):
                        if (x, y) != (i, j):
                            live_neighbors += grid[x][y]

                if grid[i][j] == 1:
                    new_grid[i][j] = 1 if 2 <= live_neighbors <= 3 else 0
                else:
                    new_grid[i][j] = 1 if live_neighbors == 3 else 0
        return new_grid

    def grid_equal(grid1, grid2):
        return all(grid1[i][j] == grid2[i][j] for i in range(n) for j in range(m))

    def find_order(start_grid_index):
        order = [start_grid_index + 1]
        current_grid = grids[start_grid_index]
        remaining_grids = list(range(k))
        remaining_grids.remove(start_grid_index)

        for _ in range(k - 1):
            found_next = False
            for next_grid_index in remaining_grids:
                next_grid = grids[next_grid_index]

                temp_grid = current_grid
                gens = 0
                while gens <= 2000:
                    if grid_equal(temp_grid, next_grid):
                        order.append(next_grid_index + 1)
                        current_grid = next_grid
                        remaining_grids.remove(next_grid_index)
                        found_next = True
                        break
                    temp_grid = next_generation(temp_grid)
                    gens+=1
            if not found_next:
                return None
        return order

    for start_index in range(k):
        order = find_order(start_index)
        if order:
            print(*order)
            return

solve()