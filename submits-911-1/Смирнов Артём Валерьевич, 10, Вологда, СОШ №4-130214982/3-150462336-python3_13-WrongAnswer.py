N = int(input())
T = int(input())
ads = [tuple(map(int, input().split())) for _ in range(N)]

time_slots = [0] * 3600

for start, end in ads:
    for i in range(max(0, start), min(3600, end)):
        time_slots[i] += 1

for i in range(3600):
    if sum(time_slots[i:i + 3600]) > T:
        print(i)
        break
else:
    print(-1)