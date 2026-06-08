n = int(input())
if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(-1)
elif n > 2:
    print(3 * 2**(n - 2))
    a = [1, 2]
    for i in range(3, n + 1):
        a.append(3 * 2**(i - 3))
    print(*a)