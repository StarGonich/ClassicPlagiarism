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

for i in range(len(events)):
    for j in range(i + 1, len(events)):
        if events[i][0] > events[j][0]:
            events[i], events[j] = events[j], events[i]

times = []
levels = []

current_level = 0
for t, delta in events:
    current_level += delta
    times.append(t)
    levels.append(current_level)

prefix_sums = [0]
for lvl in levels:
    prefix_sums.append(prefix_sums[-1] + lvl)

def binary_search(array, target):
    left, right = 0, len(array) - 1
    while left <= right:
        mid = (left + right) // 2
        if array[mid] >= target:
            right = mid - 1
        else:
            left = mid + 1
    return left

answer = -1
for i in range(len(times)):
    start_time = times[i]
    end_time = start_time + 3600
    j = binary_search(times, end_time)

    total = prefix_sums[j] - prefix_sums[i]
    if total > T:
        answer = start_time
        break

print(answer)