n = int(input())
T = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))
min_start = -1

for i in range(n):
    start_time = ads[i][0]
    end_time = start_time + 3600
    total = 0
    j = 0
    while j < n:
        t1, t2 = ads[j]
        if t1 >= end_time:
            break
        if t2 > start_time:
            intersect_start = max(t1, start_time)
            intersect_end = min(t2, end_time)
            total += (intersect_end - intersect_start)
        j += 1
    if total > T:
        min_start = start_time
        break

print(min_start)