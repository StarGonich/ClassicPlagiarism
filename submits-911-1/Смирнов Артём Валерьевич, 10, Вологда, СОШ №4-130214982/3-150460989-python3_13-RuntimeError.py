N = int(input())
T = int(input())
ads = [tuple(map(int, input().split())) for _ in range(N)]

time_slots = [0] * (10**9 + 1)

for start, end in ads:
    time_slots[start] += 1
    time_slots[end] -= 1

current_ads = 0
for i in range(10**9 + 1):
    current_ads += time_slots[i]
    if i >= 3600:
        if sum(time_slots[i - 3600 + 1:i + 1]) > T:
            print(i - 3600 + 1)
            break
else:
    print(-1)