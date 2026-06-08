N = int(input())
T = int(input())
ads = [tuple(map(int, input().split())) for _ in range(N)]

left = 0
current_sum = 0
result = -1

for start in range(0, 10**9 + 1):
	while right < N and ads[right][0] < start + 3600:
        t1, t2 = ads[right]
        overlap_start = max(t1, start)
        overlap_end = min(t2, start + 3600)
        if overlap_end > overlap_start:
            current_sum += (overlap_end - overlap_start)
        right += 1
    while left < N and ads[left][1] <= start:
        t1, t2 = ads[left]
        overlap_start = max(t1, start)
        overlap_end = min(t2, start + 3600)
        if overlap_end > overlap_start:
            current_sum -= (overlap_end - overlap_start)
        left += 1
    if current_sum > T:
        result = start
        break

print(result)