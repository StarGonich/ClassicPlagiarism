n = int(input())

all = n * (n + 1) // 2

if (all>10**9):
    print(-1)

else:
    print(all)
    if sum(range(1, n + 1)) != all:
        print(-1)
    else:
        print(*range(1, n + 1))