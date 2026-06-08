n = int(input())
T = int(input())
ads = []
for _ in range(n):
    t1, t2 = map(int, input().split())
    ads.append((t1, t2))

events = []
for t1, t2 in ads:
    events.append((t1, 1))
    events.append((t2, -1))

events.sort()

def check(x):
    total = 0
    j = 0
    for i in range(len(events)):
        if events[i][0] >= x + 3600:
            break
        if events[i][0] >= x:
            total += events[i][1]
    return total > T

left = 0
right = max(0, ads[-1][1] - 3600)
result = -1

for x in range(left, right + 1):
    if check(x):
        result = x
        break

print(result)
left = 0
right = ads[-1][1] - 3600
result = -1

for x in range(left, right + 1):
    if check(x):
        result = x
        break

print(result)
        
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