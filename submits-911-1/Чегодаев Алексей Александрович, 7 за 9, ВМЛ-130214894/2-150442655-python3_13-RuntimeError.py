n = int(input())
for i in range(1, 10 ** 9 + 1):
    l = i
    r = n
    while(l > r + 1):
        m =(l + r) // 2
        s = 0
        for j in range(m, m - n, -1):
            s += i // j
        if s == i:
            print(i)
            for g in range(m - 1, m - n - 1, -1):
                print(g, end=' ')
            exit(0)
        elif s > i:
            r = s
        else:
            l = s