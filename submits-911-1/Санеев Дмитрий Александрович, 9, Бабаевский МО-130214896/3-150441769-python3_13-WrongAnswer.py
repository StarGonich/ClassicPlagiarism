N = int(input())
T = int(input())
ads = []

for _ in range(N):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

points = []

for t1, t2 in ads:
    points.append(t1)
    points.append(t2)

points = sorted(set(points))

answer = -1

for start in points:
    end = start + 3600
    total = 0
    for t1, t2 in ads:
        if t2 <= start:
            continue
        if t1 >= end:
            continue
        overlap_start = max(t1, start)
        overlap_end = min(t2, end)
        if overlap_end > overlap_start:
            total += (overlap_end - overlap_start)
    if total > T:
        answer = start
        break

print(answer)