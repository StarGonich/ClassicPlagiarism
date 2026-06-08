n = int(input())
for i in range(2, 10**6):
    f = []
    for d in range(1, i // 2 + 1):
        if i % d == 0:
            f.append(d)
            if d != i // d:
                f.append(i // d)
    if len(f) == n and sum(set(f)) == i:
        print(i)
        print(set(f))
        break