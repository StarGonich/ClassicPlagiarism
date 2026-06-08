from collections import deque

def read_config(n, m):
    config = []
    for _ in range(n):
        row = list(map(int, input().split()))
        config.append(row)
    return config

def next_state(config, n, m):
    new_config = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            live_neighbors = 0
            for di in (-1, 0, 1):
                for dj in (-1, 0, 1):
                    if di == 0 and dj == 0:
                        continue
                    ni, nj = i + di, j + dj
                    if 0 <= ni < n and 0 <= nj < m:
                        live_neighbors += config[ni][nj]
            if config[i][j] == 1:
                if live_neighbors in (2, 3):
                    new_config[i][j] = 1
                else:
                    new_config[i][j] = 0
            else:
                if live_neighbors == 3:
                    new_config[i][j] = 1
                else:
                    new_config[i][j] = 0
    return new_config

def config_to_tuple(config):
    return tuple(tuple(row) for row in config)

def main():
    k = int(input())
    n = int(input())
    m = int(input())
    
    configs = []
    config_tuples = []
    for idx in range(k):
        config = read_config(n, m)
        configs.append(config)
        config_tuples.append(config_to_tuple(config))
    graph = [[] for _ in range(k)]
    indegree = [0] * k
    for i in range(k):
        current = configs[i]
        visited_states = set()
        visited_states.add(config_tuples[i])
        
        step = 0
        while step < 2000:
            current = next_state(current, n, m)
            current_tuple = config_to_tuple(current)
            if current_tuple in visited_states:
                break
            visited_states.add(current_tuple)
            for j in range(k):
                if j != i and current_tuple == config_tuples[j]:
                    graph[i].append(j)
                    indegree[j] += 1
            
            step += 1
    result = []
    q = deque([i for i in range(k) if indegree[i] == 0])
    while q:
        node = q.popleft()
        result.append(node + 1)
        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                q.append(neighbor)
    
    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()