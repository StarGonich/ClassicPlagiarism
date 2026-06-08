N = int(input())
T = int(input())

ads = []
for _ in range(N):
    t1, t2 = map(int, input().split()) #ввод 2 чисел разделенных пробелом
    ads.append((t1, t2))

left = 0
cs = 0
result = -1

for right in range(N):
    cs += (ads[right][1] - ads[right][0])

    while ads[right][0] - ads[left][0] >= 3600:
        cs -= (ads[left][1] - ads[left][0])
        left += 1#смещаем окно

    if (cs>T):
        start_time = ads[right][0] - (ads[right][0] - ads[left][0])
        candidate_start = ads[right][0] - (ads[right][1] - ads[right][0])
        start_time_candidate = ads[left][0]

        if (result == -1 or start_time_candidate<result):
            result = start_time_candidate
print(result)