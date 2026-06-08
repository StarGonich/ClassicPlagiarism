n = int(input())
for m in range(2, 10 ** 9):
    d = []
    for i in range(1, m):
        if m % i == 0:
            d.append(i)
    if sum(d) == m and len(d) >= n:
        print(m)
        print(''.join(map(str, d[:n])))
        break
else:
    print(-1)