import sys
from itertools import permutations

def next_generation(grid, n, m):
    """Вычисляет следующее поколение для игры 'Жизнь'"""
    new_grid = [[0] * m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            
            live_neighbors = 0
            for di in [-1, 0, 1]:
                for dj in [-1, 0, 1]:
                    if di == 0 and dj == 0:
                        continue
                    ni, nj = i + di, j + dj
                    if 0 <= ni < n and 0 <= nj < m:
                        live_neighbors += grid[ni][nj]
            
            
            if grid[i][j] == 1:
               
                if live_neighbors == 2 or live_neighbors == 3:
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = 0
            else:
               
                if live_neighbors == 3:
                    new_grid[i][j] = 1
                else:
                    new_grid[i][j] = 0
    
    return new_grid

def grids_equal(grid1, grid2, n, m):
    """Проверяет, равны ли две конфигурации"""
    for i in range(n):
        for j in range(m):
            if grid1[i][j] != grid2[i][j]:
                return False
    return True

def is_valid_sequence(order, configurations, n, m):
    """Проверяет, является ли порядок валидной последовательностью эволюции"""
    for i in range(len(order) - 1):
        current_config = configurations[order[i] - 1]
        next_config = configurations[order[i + 1] - 1]
        
        
        computed_next = next_generation(current_config, n, m)
        
        
        if not grids_equal(computed_next, next_config, n, m):
            return False
    
    return True

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    idx = 0
    k = int(data[idx]); idx += 1
    n = int(data[idx]); idx += 1
    m = int(data[idx]); idx += 1
    
    configurations = []
    
    
    for _ in range(k):
        config = []
        for i in range(n):
            row = []
            for j in range(m):
                row.append(int(data[idx])); idx += 1
            config.append(row)
        configurations.append(config)
    
    
    all_orders = permutations(range(1, k + 1))
    

    for order in all_orders:
        if is_valid_sequence(order, configurations, n, m):
            print(" ".join(map(str, order)))
            return
    
   
    print(" ".join(map(str, range(1, k + 1))))

if __name__ == "__main__":
    main()