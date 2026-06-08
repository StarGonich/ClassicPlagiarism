n = int(input())
sum_prev = (n - 1) * n // 2
m = sum_prev + (n + 1)

divisors = list(range(1, n + 1))
divisors.append(n + 1)

if m <= 10**9:
    print(m)
    print(' '.join(map(str, divisors)))
else:
    print(-1)