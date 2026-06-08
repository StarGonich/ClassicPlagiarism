n = int(input())
if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(-1)
else:
    m = [1, 2, 3]
    x = 6
    while n > 3:
        n -= 1
        m.append(x)
        x *= 2
    print(x)
    print(*m)
