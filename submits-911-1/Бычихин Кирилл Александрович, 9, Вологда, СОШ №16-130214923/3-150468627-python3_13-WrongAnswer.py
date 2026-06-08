N = int(input())
T = int(input())

ads = [tuple(map(int, input().split())) for _ in range(N)]

# поинтеры в пайтон йоу(другие как в С)
start_idx = 0
current_sum = 0
res = -1

for end_idx in range(N):
    t1_end, t2_end = ads[end_idx]
    #рекламу в текущую сумму
    current_sum += (t2_end - t1_end)
    #сдвигаем окноо начала
    while t1_end - ads[start_idx][0] >= 3600:
        current_sum -= (ads[start_idx][1] - ads[start_idx][0])
        start_idx += 1
    if (ads[start_idx][0] + 3600 > t2_end):
        pass
    else:
        st = ads[start_idx][0]
        end_time = st + 3600
        if (current_sum > T):
            if (res == -1 or st < res):
                res = st
print(res)