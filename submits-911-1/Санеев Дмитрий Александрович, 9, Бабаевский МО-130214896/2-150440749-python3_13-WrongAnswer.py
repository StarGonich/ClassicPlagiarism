n = int(input())

sum_first = (n - 1) * n // 2

m = sum_first

while True:
    last_divisor = m - sum_first
    if last_divisor > 0 and m % last_divisor == 0:
        divisors = list(range(1, n))
        divisors.append(last_divisor)
        print(m)
        print(' '.join(map(str, divisors)))
        break
    m += 1
    if m > 10**9:
        print(-1)
        break