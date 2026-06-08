n = int(input())
T = int(input())

ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

ads.sort(key=lambda x: x[0])

left = 0
current_sum = 0
answer = -1

for i in range(n):
    start_time = ads[i][0]
    end_time = start_time + 3600

    while right < n and ads[right][0] < end_time:
        t1, t2 = ads[right]
        if t2 > start_time:
            intersect_start = max(t1, start_time)
            intersect_end = min(t2, end_time)
            current_sum += (intersect_end - intersect_start)
        right += 1

    if current_sum > T:
        answer = start_time
        break

import sys
n = int(sys.stdin.readline())
T = int(sys.stdin.readline())

ads = []
for _ in range(n):
    t1, t2 = map(int, sys.stdin.readline().split())
    ads.append((t1, t2))
ads.sort(key=lambda x: x[0])

answer = -1
for i in range(n):
    start_time = ads[i][0]
    end_time = start_time + 3600
    total = 0
    for j in range(n):
        t1, t2 = ads[j]
        if t1 >= end_time:
            break
        if t2 > start_time:
            intersect_start = max(t1, start_time)
            intersect_end = min(t2, end_time)
            total += (intersect_end - intersect_start)
    if total > T:
        answer = start_time
        break

print(answer)