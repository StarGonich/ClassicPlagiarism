N = int(input())
T = int(input())
ads = []
for _ in range(N):
    t1, t2 = map(int, input().split())
    ads.append([t1, t2])

if N == 0:
    print(-1)
    exit()

left = 0
cur = 0
ans = -1
found = False

for right in range(N):
    start = ads[right][0]
    end = ads[right][1]

    while left < N and ads[left][1] <= start:
        left += 1

    time = start
    while time <= end:
        window_start = time
        window_end = time + 3600
        total = 0
        i = left
        while i <= right:
            seg_start = max(ads[i][0], window_start)
            seg_end = min(ads[i][1], window_end)
            if seg_start < seg_end:
                total += seg_end - seg_start
            i += 1
        j = right + 1
        while j < N and ads[j][0] < window_end:
            seg_start = max(ads[j][0], window_start)
            seg_end = min(ads[j][1], window_end)
            if seg_start < seg_end:
                total += seg_end - seg_start
            j += 1

        if total > T:
            print(window_start)
            exit()

        if time + 3600 > ads[right][1]:
            break
        time += 1

    if time > end:
        time = end

print(-1)