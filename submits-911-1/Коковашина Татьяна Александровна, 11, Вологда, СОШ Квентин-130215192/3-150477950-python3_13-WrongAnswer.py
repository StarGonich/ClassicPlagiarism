p = int(input())
T = int(input())

a = [tuple(map(int, input().split())) for _ in range(p)]

c = [0]
for x, y in a:
    c.append(y)

for s in c:
    e = s + 3600
    t = 0
    for x, y in a:
        if y <= s:
            continue
        if x >= e:
            break
        t += min(y, e) - max(x, s)
    if t > T:
        print(s)
        exit()

print(-1)