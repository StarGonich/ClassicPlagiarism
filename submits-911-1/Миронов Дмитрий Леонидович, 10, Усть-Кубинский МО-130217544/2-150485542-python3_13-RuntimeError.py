n = int(input())
if n == 2:
    print(-1)
    exit()
for m in range(1, 5000):
    c = []
    i = 1
    while i * i <= m:
        if m % i == 0:
            c.append(i)
            if i * i != m:
                c.append(m // i)
        i += 1
    c.sort()
    if len(c) < n:
        continue
    chose = c[:n]
    if sum(chose) == m:
        print(m)
        print(*chose)
        exit()
print(-1)