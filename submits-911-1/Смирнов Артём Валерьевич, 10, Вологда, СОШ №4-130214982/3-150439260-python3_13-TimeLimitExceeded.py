def solve():
    n = int(input())
    t = int(input())
    ads = []
    for _ in range(n):
        t1, t2 = map(int, input().split())
        ads.append((t1, t2))

    for start_time in range(0, 1000001): # Перебираем все возможные начала часа
        hour_end = start_time + 3600
        total_ad_time = 0
        for ad_start, ad_end in ads:
            # Вычисляем пересечение рекламной вставки с текущим часом
            intersection_start = max(start_time, ad_start)
            intersection_end = min(hour_end, ad_end)

            # Если есть пересечение, добавляем время рекламы
            if intersection_start < intersection_end:
                total_ad_time += (intersection_end - intersection_start)

        # Если суммарное время рекламы превышает лимит, выводим время начала часа
        if total_ad_time > t:
            print(start_time)
            return

    # Если не найдено ни одного часа, нарушающего закон, выводим -1
    print("-1")

solve()