N = int(input())
T = int(input())

ads = []
for _ in range(N):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

ads.sort(key=lambda x: x[0])

left = 0
current_sum = 0
max_start_time = -1


for right in range(N):
    t1, t2 = ads[right]
    while left <= right:
        total_time = 0
        start_time = max(ads[left][0], 0)
        end_time = ads[right][1]
        for i in range(left, right + 1):
            s, e = ads[i]
            overlap_start = max(s, start_time)
            overlap_end = min(e, end_time)
            if overlap_end > overlap_start:
                total_time += (overlap_end - overlap_start)
        if total_time <= T:
            if total_time <= T:
                max_start_time = max(ads[left][0], 0)
            break
        else:
            left += 1

print(max_start_time)