n = int(input())
if n == 1:
    print(52)
    print(52)
elif n == 2:
    print(-1)
elif n == 3:
    print(6)
    print(3, 2, 1)
else:
    print(3 * (1 << n))
    for i in range(n - 1, 0, -1):
        print(3 * (1 << i), end=" ")
    print(4, 2)
