def solve():
    n = int(input())
    t = int(input())
    ads = []
    for _ in range(n):
        ads.append(list(map(int, input().split())))

    for start_time in range(0, 100000):  # Перебираем все возможные начала часовых интервалов
        total_ad_time = 0
        for ad in ads:
            ad_start = ad[0]
            ad_end = ad[1]

            # Определяем пересечение рекламного интервала с текущим часовым интервалом
            intersection_start = max(start_time, ad_start)
            intersection_end = min(start_time + 3600, ad_end)

            # Если есть пересечение, добавляем его длительность к общему времени рекламы
            if intersection_start < intersection_end:
                total_ad_time += (intersection_end - intersection_start)

        # Проверяем, не превышает ли общее время рекламы лимит T
        if total_ad_time > t:
            print(start_time)
            return

    # Если ни один часовой интервал не превысил лимит, выводим -1
    print(-1)

solve()
