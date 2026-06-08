n = int(input())

sum_first_n = n * (n + 1) // 2

if sum_first_n > 10**9:
    print(-1)
else:
    m = sum_first_n
    divisors = list(range(1, n))
    last_divisor = m - sum(divisors)
    divisors.append(last_divisor)
    print(m)
    print(' '.join(map(str, divisors)))