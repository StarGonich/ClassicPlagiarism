import sys
N_str = sys.stdin.readline()
N = int(N_str)
T_str = sys.stdin.readline()
T = int(T_str)
ad_intervals = []
for _ in range(N):
    line = sys.stdin.readline()
    t1, t2 = map(int, line.split())
    ad_intervals.append((t1, t2))

if N == 0:
    print(-1)
else:
    critical_points = {0}
    for t1, t2 in ad_intervals:
        critical_points.add(t1)
        critical_points.add(max(0, t2 - 3600))
    
    sorted_points = sorted(list(critical_points))
    
    left_ad_index = 0
    found = False
    for window_start in sorted_points:
        window_end = window_start + 3600
        current_ad_duration = 0
        
        while left_ad_index < N and ad_intervals[left_ad_index][1] <= window_start:
            left_ad_index += 1
        for i in range(left_ad_index, N):
            ad_start, ad_end = ad_intervals[i]
            
            if ad_start >= window_end:
                break
            
            intersection_start = max(window_start, ad_start)
            intersection_end = min(window_end, ad_end)
            
            if intersection_start < intersection_end:
                current_ad_duration += (intersection_end - intersection_start)
        
        if current_ad_duration > T:
            print(window_start)
            found = True
            break
    
    if not found:
        print(-1)
