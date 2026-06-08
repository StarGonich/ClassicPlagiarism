n = int(input())

all = n * (n + 1) // 2

if (all>10**9):
    print(-1)
else:
    print(all)
    print(*range(1, n + 1))