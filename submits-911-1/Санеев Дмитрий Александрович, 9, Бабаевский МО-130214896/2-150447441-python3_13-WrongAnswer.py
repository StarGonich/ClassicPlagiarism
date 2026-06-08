n = int(input())
m = n * (n + 1) // 2

if m <= 10**9:
    print(m)
    print(' '.join(str(i) for i in range(1, n + 1)))
else:
    print(-1)