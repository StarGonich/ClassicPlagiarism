n = int(input())

sum_first = (n - 1) * n // 2
m = sum_first + 1 

last_divisor = m - sum_first

if last_divisor > 0 and m % last_divisor == 0:
    divisors = list(range(1, n))
    divisors.append(last_divisor)
    print(m)
    print(' '.join(map(str, divisors)))
else:
    print(-1)