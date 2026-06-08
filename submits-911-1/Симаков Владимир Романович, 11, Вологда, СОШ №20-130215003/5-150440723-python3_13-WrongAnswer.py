import sys

def solve():
    try:
        k = int(sys.stdin.readline())
        n = int(sys.stdin.readline())
        m = int(sys.stdin.readline())

        configs = []
        for _ in range(k):
            config_data = []
            for _ in range(n):
                line = sys.stdin.readline().strip().split()
                row = [int(x) for x in line if x]
                config_data.append(row)
            configs.append(config_data)

        def simulate_step(current_config):
            next_config = [[0 for _ in range(m)] for _ in range(n)]
            for i in range(n):
                for j in range(m):
                    live_neighbors = 0
                    for di in [-1, 0, 1]:
                        for dj in [-1, 0, 1]:
                            if di == 0 and dj == 0:
                                continue
                            ni, nj = i + di, j + dj
                            if 0 <= ni < n and 0 <= nj < m and current_config[ni][nj] == 1:
                                live_neighbors += 1
                    
                    if current_config[i][j] == 1:
                        if live_neighbors == 2 or live_neighbors == 3:
                            next_config[i][j] = 1
                        else:
                            next_config[i][j] = 0
                    else:
                        if live_neighbors == 3:
                            next_config[i][j] = 1
                        else:
                            next_config[i][j] = 0
            return next_config

        transitions = [[False for _ in range(k)] for _ in range(k)]
        predecessor_count = [0] * k
        successor_count = [0] * k

        for i in range(k):
            next_config = simulate_step(configs[i])
            for j in range(k):
                if next_config == configs[j]:
                    transitions[i][j] = True
                    successor_count[i] += 1
                    predecessor_count[j] += 1
                    break

        start_index = -1
        for i in range(k):
            if predecessor_count[i] == 0:
                start_index = i
                break
        
        result_sequence = []
        current_index = start_index

        for _ in range(k):
            result_sequence.append(current_index + 1)
            for j in range(k):
                if transitions[current_index][j]:
                    current_index = j
                    break

        print(*(result_sequence))

    except EOFError:
        pass
    except ValueError:
        pass

solve()
