n = int(input())
T = int(input())
ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

max_time = ads[-1][1]
events = []
for t1, t2 in ads:
    events.append((t1, 1))
    events.append((t2, -1))

events.sort()
total = 0
j = 0
result = -1

for i in range(max_time + 1):
    while j < len(events) and events[j][0] <= i:
        total += events[j][1]
        j += 1
    
    if i + 3600 > max_time:
        break
        
    end_idx = j
    temp_total = total
    temp_j = j
    
    while temp_j < len(events) and events[temp_j][0] < i + 3600:
        temp_total += events[temp_j][1]
        temp_j += 1
    
    if temp_total > T:
        result = i
        break

print(result)