import sys
from collections import deque

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
                if live_neighbors == 3:
                    new_grid[i][j] = 1
    
    return new_grid

def grid_to_tuple(grid):
    """Преобразует сетку в кортеж для использования как ключ"""
    return tuple(tuple(row) for row in grid)

def find_evolution_order(configurations, n, m):
    """Находит порядок эволюции с помощью поиска в графе"""
    k = len(configurations)
    
   
    config_to_index = {}
    for i, config in enumerate(configurations):
        config_to_index[grid_to_tuple(config)] = i + 1
    

    graph = {}
    for i, config in enumerate(configurations):
        next_config = next_generation(config, n, m)
        next_config_tuple = grid_to_tuple(next_config)
        if next_config_tuple in config_to_index:
            graph[i + 1] = config_to_index[next_config_tuple]
    
    
    has_incoming = set(graph.values())
    all_nodes = set(range(1, k + 1))
    start_nodes = all_nodes - has_incoming
    
    if len(start_nodes) != 1:
        
        return list(range(1, k + 1))
    
    start = start_nodes.pop()
    

    order = [start]
    current = start
    while current in graph:
        current = graph[current]
        order.append(current)
    
    return order

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
    
   
    order = find_evolution_order(configurations, n, m)
    print(" ".join(map(str, order)))

if __name__ == "__main__":
    main()