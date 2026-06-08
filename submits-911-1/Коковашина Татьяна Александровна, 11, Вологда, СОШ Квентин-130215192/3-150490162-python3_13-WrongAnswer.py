n = int(input())
T = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

cuvaki = [0]
for t1, t2 in ads:
    cuvaki.append(t2)

ans = -1
for start in cuvaki:
    end = start + 3600
    total = 0
    for t1, t2 in ads:
        if t2 <= start:
            continue
        if t1 >= end:
            break
        total += min(t2, end) - max(t1, start)
    if total > T:
        ans = start
        break

print(ans)