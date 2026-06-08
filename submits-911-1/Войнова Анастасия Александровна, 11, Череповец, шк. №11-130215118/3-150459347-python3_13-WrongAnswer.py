n, t = int(input()), int(input())
l = [[int(k) for k in input().split()] for _ in range(n)]
h = 0
h1 = 3600
end = l[-1][1]
i = 0
while h <= end:
    f = True
    s = []  # реклама
    while True:
        if l[i][1] > h1:
            break
        s.append(l[i][1] - l[i][0])
        if sum(s) > t:
            f = False
            break
        if l[i] == l[-1]:
            break
        i += 1
    if f == False:
        print((l[i][0] - 3600 * (l[i][0] // 3600)) + s[-1] - (sum(s) - t) + 1)
        break
    h, h1 = h + 3601, h1 + 3600
if f:
    print(-1)