n = int(input())

sum_n = n * (n + 1) // 2

if sum_n <= 10**9:
    print(sum_n)
    print(' '.join(str(i) for i in range(1, n + 1)))
else:
    print(-1)