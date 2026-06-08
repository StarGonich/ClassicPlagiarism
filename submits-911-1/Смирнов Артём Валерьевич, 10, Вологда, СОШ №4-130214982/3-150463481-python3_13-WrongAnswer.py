def solve():
    n = int(input())
    t = int(input())
    ads = []
    for _ in range(n):
        ads.append(list(map(int, input().split())))

    # Создаем множество уникальных времён начала и конца рекламы
    potential_starts = sorted(list(set([ad[0] for ad in ads] + [ad[1] for ad in ads])))

    for start_time in potential_starts:
        total_ad_time = 0
        for ad in ads:
            ad_start = ad[0]
            ad_end = ad[1]

            intersection_start = max(start_time, ad_start)
            intersection_end = min(start_time + 3600, ad_end)

            if intersection_start < intersection_end:
                total_ad_time += (intersection_end - intersection_start)

        if total_ad_time > t:
            print(start_time)
            return

    print(-1)

solve()
