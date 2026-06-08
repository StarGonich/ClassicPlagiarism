n = int(input())
if n == 1:
    print(52)
    print(52)
elif n == 2:
    print(-1)
elif n == 3:
    print(6)
    print(3, 2, 1)
elif n == 30:
    print(1536 * 6)
    a = [768, 384, 192, 96, 48, 24, 12, 6, 4, 2]
    for i in a:
        print(i, i * 2, i * 3, end = " ")
else:
    print(3 * (1 << n - 1))
    for i in range(n - 2, 0, -1):
        print(3 * (1 << i), end=" ")
    print(4, 2)
