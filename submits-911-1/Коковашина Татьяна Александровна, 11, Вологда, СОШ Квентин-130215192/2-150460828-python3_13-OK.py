n = int(input())

if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(-1)
else:
    m = 6 * (1 << (n - 3))
    divisors = [1, 2, 3]
    x = 6
    for i in range(n - 3):
        divisors.append(x)
        x *= 2
    print(m)
    print(' '.join(map(str, divisors)))