n = int(input())
s = n * (n + 1) // 2
if s > 10**9:
    print(-1)
else:
    print(s)
    print(' '.join(map(str, range(1, n + 1)))) #вывод join