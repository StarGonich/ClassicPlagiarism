import sys

N = int(sys.stdin.readline())
T = int(sys.stdin.readline())


events = []

for _ in range(N):
    t1, t2 = map(int, sys.stdin.readline().split())
    if t2 - t1 > 0:
        events.append((t1, t2 - t1))

if not events:
    print(-1)
    exit()

events.sort()

queue = []
current_ad_time = 0
min_start_time = -1

for i in range(len(events)):
    current_time, duration = events[i]
    
    queue.append((current_time, duration))
    current_ad_time += duration

    while queue[0][0] <= current_time - 3600:
        current_ad_time -= queue[0][1]
        queue.pop(0)

    if current_ad_time > T:
        
        low = max(0, queue[0][0] - 3599)
        high = current_time
        best_candidate = -1

        while low <= high:
            mid = (low + high) // 2
            
            test_ad_time = 0
            for event_time, event_duration in queue:

                intersection_start = max(event_time, mid)
                intersection_end = min(event_time + event_duration, mid + 3600)

                if intersection_end > intersection_start:
                    test_ad_time += (intersection_end - intersection_start)

            if test_ad_time > T:
                best_candidate = mid
                high = mid - 1
            else:
                low = mid + 1
        
        if best_candidate != -1:
            if min_start_time == -1 or best_candidate < min_start_time:
                min_start_time = best_candidate

print(min_start_time)
