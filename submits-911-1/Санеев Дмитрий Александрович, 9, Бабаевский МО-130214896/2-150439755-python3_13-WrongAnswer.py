n = int(input())

m = n * (n + 1) // 2

print(m)

divisors = list(range(1, n + 1))
print(' '.join(map(str, divisors)))