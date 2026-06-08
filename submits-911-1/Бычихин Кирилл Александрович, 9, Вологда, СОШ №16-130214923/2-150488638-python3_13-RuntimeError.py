n = int(input())

m = n * (n + 1) // 2

divisors = list(range(1, n + 1))
for d in divisors:
    if m % d != 0:
        print(-1)
        exit()

print(m)
print(' '.join(map(str, divisors)))