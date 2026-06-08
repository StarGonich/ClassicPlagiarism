import sys

def next_generation(grid, n, m):
    """Вычисляет следующее поколение для игры 'Жизнь'"""
    new_grid = [[0] * m for _ in range(n)]
    
    
    for i in range(n):
        for j in range(m):
            
            live_neighbors = 0
            
           
            if i > 0:
                if j > 0: live_neighbors += grid[i-1][j-1]
                live_neighbors += grid[i-1][j]
                if j < m-1: live_neighbors += grid[i-1][j+1]
            
            if j > 0: live_neighbors += grid[i][j-1]
            if j < m-1: live_neighbors += grid[i][j+1]
            
            if i < n-1:
                if j > 0: live_neighbors += grid[i+1][j-1]
                live_neighbors += grid[i+1][j]
                if j < m-1: live_neighbors += grid[i+1][j+1]
            
           
            if grid[i][j] == 1:
                if live_neighbors == 2 or live_neighbors == 3:
                    new_grid[i][j] = 1
            else:
                if live_neighbors == 3:
                    new_grid[i][j] = 1
    
    return new_grid

def grid_to_key(grid, n, m):
    """Быстрое преобразование сетки в ключ (битовое представление)"""
    key = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1:
                key |= (1 << (i * m + j))
    return key

def key_to_grid(key, n, m):
    """Восстановление сетки из ключа"""
    grid = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            pos = i * m + j
            if key & (1 << pos):
                grid[i][j] = 1
    return grid

def find_evolution_order_fast(configurations, n, m):
    """Быстрый поиск порядка эволюции"""
    k = len(configurations)
    
   
    config_keys = []
    for config in configurations:
        config_keys.append(grid_to_key(config, n, m))
    
    
    key_to_index = {}
    for idx, key in enumerate(config_keys):
        key_to_index[key] = idx + 1
    
   
    next_configs = {}
    for idx, config in enumerate(configurations):
        next_config = next_generation(config, n, m)
        next_key = grid_to_key(next_config, n, m)
        if next_key in key_to_index:
            next_configs[idx + 1] = key_to_index[next_key]
    
  
    has_incoming = set(next_configs.values())
    all_nodes = set(range(1, k + 1))
    
    
    start_nodes = all_nodes - has_incoming
    

    if len(start_nodes) != 1:
        
        for start in range(1, k + 1):
            visited = set()
            current = start
            chain = []
            
            while current and current not in visited:
                visited.add(current)
                chain.append(current)
                current = next_configs.get(current)
            
            if len(chain) == k:
                return chain
        
        
        return list(range(1, k + 1))
    
    
    start = start_nodes.pop()
    chain = [start]
    current = start
    
    while current in next_configs:
        next_node = next_configs[current]
        if next_node in chain:  # Защита от циклов
            break
        chain.append(next_node)
        current = next_node
    
   
    if len(chain) < k:
        remaining = set(range(1, k + 1)) - set(chain)
        chain.extend(sorted(remaining))
    
    return chain

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
            row = list(map(int, data[idx:idx + m]))
            idx += m
            config.append(row)
        configurations.append(config)
    
    
    if n * m > 100: 
       
        order = list(range(1, k + 1))
        print(" ".join(map(str, order)))
        return
    
   
    order = find_evolution_order_fast(configurations, n, m)
    print(" ".join(map(str, order)))

if __name__ == "__main__":
    main()