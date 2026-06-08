from collections import deque

def count_neighbors(x, y, grid):
    n = len(grid)
    m = len(grid[0])
    neighbors = [(dx, dy) for dx in [-1, 0, 1] for dy in [-1, 0, 1]]
    alive_count = 0
    
    for nx, ny in neighbors:
        if nx == 0 and ny == 0:
            continue
        
        new_x = x + nx
        new_y = y + ny
        
        if 0 <= new_x < n and 0 <= new_y < m:
            alive_count += grid[new_x][new_y]
            
    return alive_count


def next_state(current_grid):
    n = len(current_grid)
    m = len(current_grid[0])
    next_grid = [[0]*m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            live_neighbors = count_neighbors(i, j, current_grid)
            
            if current_grid[i][j]:  
                if live_neighbors == 2 or live_neighbors == 3:
                    next_grid[i][j] = 1
            else:  
                if live_neighbors == 3:
                    next_grid[i][j] = 1
                    
    return next_grid



k = int(input())  
n = int(input()) 
m = int(input())  

configurations = []
for _ in range(k):
    config = [list(map(int, input().split())) for _ in range(n)]
    configurations.append(config)

graph = {i+1: [] for i in range(k)}

for i in range(k):
    for j in range(k):
        if i != j:
            if next_state(configurations[i]) == configurations[j]:
                graph[i+1].append(j+1)
                
in_degree = {v: 0 for v in graph}
for u in graph:
    for v in graph[u]:
        in_degree[v] += 1

queue = deque([v for v in in_degree if in_degree[v] == 0])
result_order = []

while queue:
    vertex = queue.popleft()
    result_order.append(vertex)
    
    for neighbor in graph[vertex]:
        in_degree[neighbor] -= 1
        if in_degree[neighbor] == 0:
            queue.append(neighbor)

print(' '.join(map(str, result_order)))