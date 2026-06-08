import sys

N = int(sys.stdin.readline())
T = int(sys.stdin.readline())
ad_intervals = []
for _ in range(N):
    line = sys.stdin.readline()
    if line:
        ad_intervals.append(tuple(map(int, line.split())))

if N == 0:
    print("-1")
    exit()

potential_starts = {0}
for t1, t2 in ad_intervals:
    potential_starts.add(t1)
    potential_starts.add(max(0, t2 - 3600))

sorted_starts = sorted(list(potential_starts))

ad_intervals_sorted = sorted(ad_intervals)

left_ptr = 0
min_start_time = -1

for start_time in sorted_starts:
    end_time = start_time + 3600
    current_ad_duration = 0

    while left_ptr < N and ad_intervals_sorted[left_ptr][1] <= start_time:
        left_ptr += 1

    for i in range(left_ptr, N):
        ad_start, ad_end = ad_intervals_sorted[i]
        
        if ad_start >= end_time:
            break
        
        intersection_start = max(start_time, ad_start)
        intersection_end = min(end_time, ad_end)
        
        if intersection_start < intersection_end:
            current_ad_duration += (intersection_end - intersection_start)
    
    if current_ad_duration > T:
        min_start_time = start_time
        break

print(min_start_time)
