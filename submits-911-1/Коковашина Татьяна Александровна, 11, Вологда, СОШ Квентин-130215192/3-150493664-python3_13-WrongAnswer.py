n = int(input())
T = int(input())

ads = []
for i in range(n):
    data = input().split()
    t1 = int(data[0])
    t2 = int(data[1])
    ads.append((t1, t2))

cuvaki = [0]
for i in range(len(ads)):
    t1, t2 = ads[i]
    cuvaki.append(t2)

ans = -1
for idx in range(len(cuvaki)):
    start = cuvaki[idx]
    end = start + 3600
    total = 0
    for j in range(len(ads)):
        t1, t2 = ads[j]
        if t2 <= start:
            continue
        if t1 >= end:
            break
        total += min(t2, end) - max(t1, start)
    if total > T:
        ans = start
        break

print(ans)