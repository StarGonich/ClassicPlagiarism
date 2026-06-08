import sys

N = int(sys.stdin.readline())
T = int(sys.stdin.readline())
ads = []
for _ in range(N):
    t1, t2 = map(int, sys.stdin.readline().split())
    ads.append((t1, t2))

events = []
for t1, t2 in ads:
    duration = t2 - t1
    events.append((t1, duration))
    events.append((t2, -duration))

events.sort()

max_ad_time = 0
result_time = -1

for i in range(len(events)):
    current_time = events[i][0]
    total_ad_time = 0
    for j in range(len(events)):
        if events[j][0] >= current_time and events[j][0] < current_time + 3600:
            total_ad_time += events[j][1]
    if total_ad_time > T:
        
        start_search_time = max(0, events[i][0] - 3599)
        end_search_time = events[i][0]
        
        low = start_search_time
        high = end_search_time
        candidate = -1
        
        while low <= high:
            mid = (low + high) // 2
            test_ad_time = 0
            for t1, t2 in ads:
                intersection_start = max(t1, mid)
                intersection_end = min(t2, mid + 3600)
                if intersection_end > intersection_start:
                    test_ad_time += (intersection_end - intersection_start)
            
            if test_ad_time > T:
                candidate = mid
                high = mid - 1
            else:
                low = mid + 1
        
        if candidate != -1:
            if result_time == -1 or candidate < result_time:
                result_time = candidate

if result_time == -1 and max_ad_time > T:
    
    start_search_time = 0
    end_search_time = ads[-1][1]
    
    low = start_search_time
    high = end_search_time
    candidate = -1
    
    while low <= high:
        mid = (low + high) // 2
        test_ad_time = 0
        for t1, t2 in ads:
            intersection_start = max(t1, mid)
            intersection_end = min(t2, mid + 3600)
            if intersection_end > intersection_start:
                test_ad_time += (intersection_end - intersection_start)

        if test_ad_time > T:
            candidate = mid
            high = mid - 1
        else:
            low = mid + 1
    
    if candidate != -1:
        result_time = candidate

print(result_time)
