n = int(input())

sum_prev = (n - 1) * n // 2

m = sum_prev + 1

divisors = list(range(1, n))
last_divisor = m - sum_prev

if last_divisor > 0 and last_divisor not in divisors and last_divisor <= 10**9:
    divisors.append(last_divisor)
    print(m)
    print(' '.join(map(str, divisors)))
else:
    print(-1)