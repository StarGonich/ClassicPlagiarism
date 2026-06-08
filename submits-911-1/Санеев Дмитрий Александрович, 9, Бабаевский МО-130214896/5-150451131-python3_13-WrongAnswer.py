def read_input():
    k = int(input())
    n = int(input())
    m = int(input())
    configs = []
    for _ in range(k):
        matrix = []
        for _ in range(n):
            row = list(map(int, input().split()))
            matrix.append(row)
        configs.append(matrix)
    return k, n, m, configs

def count_alive_neighbors(grid, x, y, n, m):
    count = 0
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            if dx == 0 and dy == 0:
                continue
            nx = x + dx
            ny = y + dy
            if 0 <= nx < n and 0 <= ny < m:
                count += grid[nx][ny]
    return count

def prev_state(current, n, m):
    prev = []
    for _ in range(n):
        prev.append([0]*m)
    for i in range(n):
        for j in range(m):
            alive_neighbors = count_alive_neighbors(current, i, j, n, m)
            if current[i][j] == 1:
                if alive_neighbors == 2 or alive_neighbors == 3:
                    prev[i][j] = 1
                else:
                    prev[i][j] = 0
            else:
                if alive_neighbors == 3:
                    prev[i][j] = 1
                else:
                    prev[i][j] = 0
    return prev

def configurations_equal(a, b):
    n = len(a)
    m = len(a[0])
    for i in range(n):
        for j in range(m):
            if a[i][j] != b[i][j]:
                return False
    return True

def main():
    k, n, m, configs = read_input()
    order = [0] * k
    used = [False] * k
    order[k-1] = k-1
    used[k-1] = True

    for idx in range(k-1, 0, -1):
        current_config = configs[order[idx]]
        for prev_idx in range(k):
            if not used[prev_idx]:
                candidate = configs[prev_idx]
                prev_candidate = prev_state(current_config, n, m)
                if configurations_equal(prev_candidate, candidate):
                    order[idx-1] = prev_idx
                    used[prev_idx] = True
                    break

    print(' '.join(str(i+1) for i in order))