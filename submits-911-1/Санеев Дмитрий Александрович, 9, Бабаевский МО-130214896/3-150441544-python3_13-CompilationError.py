import sys
input = sys.stdin.read

data = input().split()
N = int(data[0])
T = int(data[1])
ads = []
idx = 2
for _ in range(N):
    t1 = int(data[idx])
    t2 = int(data[idx+1])
    idx += 2
    ads.append((t1, t2))

left = 0
current_sum = 0
answer = -1

for right in range(N)
    t1, t2 = ads[right]
    overlap_start = max(t1, 0)
    overlap_end = min(t2, 10**9)
   
points = []

for t1, t2 in ads:
    points.append(t1)
    points.append(t2)

points = sorted(set(points))

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