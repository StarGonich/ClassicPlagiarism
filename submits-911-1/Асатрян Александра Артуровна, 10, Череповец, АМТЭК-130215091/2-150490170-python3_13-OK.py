n = int(input())
if n == 1:
    print(1)
    print(1)
elif n == 2:
    print(-1)
else:
    a = [1, 2, 3]
    for i in range(n - 3):
        a.append(a[-1] * 2)
    print(sum(a))
    print(*a)