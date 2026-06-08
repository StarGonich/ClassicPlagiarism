n = int(input())
if n == 1:
    print(1)
else:
    print(2**(n - 2) * 3)
    dp = [1, 2]
    for i in range(3, n + 1):
        dp.append(3 * 2**(i - 3))
    print(*dp)