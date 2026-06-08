def solve():
    n = int(input())
    t_max = int(input())
    ads = []
    for _ in range(n):
        ads.append(tuple(map(int, input().split())))

    for start_time in range(0, 1000000): # Проходим по всем возможным точкам часа
        end_time = start_time + 3600
        total_time = 0
        for ad_start, ad_end in ads:
            intersection_start = max(start_time, ad_start)
            intersection_end = min(end_time, ad_end)

            if intersection_start < intersection_end:
                total_time += (intersection_end - intersection_start)

        if total_time > t_max:
            print(start_time)
            return

    print("-1")

solve()
