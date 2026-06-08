def solve():
    n = int(input())
    t = int(input())
    ads = []
    for _ in range(n):
        t1, t2 = map(int, input().split())
        ads.append((t1, t2))

    # Сортируем рекламные вставки по времени начала. Это помогает избежать
    # полного перебора и уменьшает количество итераций.
    ads.sort()

    max_time = ads[-1][1] if ads else 0 #Максимальное время окончания рекламной вставки

    for start_time in range(0, max_time + 1): #Перебираем все точки начала часа
        hour_end = start_time + 3600       
        total_ad_time = 0

        for ad_start, ad_end in ads:
            intersection_start = max(start_time, ad_start)
            intersection_end = min(hour_end, ad_end)

            if intersection_start < intersection_end:
                  total_ad_time += (intersection_end - intersection_start)

        if total_ad_time > t:
            print(start_time)
            return

    print("-1")

solve()