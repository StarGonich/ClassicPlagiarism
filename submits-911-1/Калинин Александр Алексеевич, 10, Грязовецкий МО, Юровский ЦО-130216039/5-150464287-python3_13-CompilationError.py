import sys
sys.setrecursionlimit(10**7)

k = int(input())
n = int(input())
m = int(input())

configs = []
for _ in range(k):
    config = [list(map(int, input().split())) for _ in range(n)]
    configs.append(config)

# Функция для получения следующего состояния по правилам игры "Жизнь"
def next_state(grid):
    new_grid = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            live_neighbors = 0
            for di in [-1,0,1]:
                for dj in [-1,0,1]:
                    if di == 0 and dj == 0:
                        continue
                    ni, nj = i + di, j + dj
                    if 0 <= ni < n and 0 <= nj < m:
                        live_neighbors += grid[ni][nj]
            if