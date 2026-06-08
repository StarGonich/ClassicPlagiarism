n = int(input())

m = n * (n + 1) // 2
end = False
divisors = list(range(1, n + 1))
for d in divisors:
    if m % d != 0:
        print(-1)
        end = True
        break


if not end:
    print(m)
    for d in divisors:
        print(d, end=' ')