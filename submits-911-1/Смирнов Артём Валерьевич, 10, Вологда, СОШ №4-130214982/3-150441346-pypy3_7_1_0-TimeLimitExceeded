def solve():
    n = int(input())
    t_max = int(input())
    ads = []
    for _ in range(n):
        ads.append(tuple(map(int, input().split())))

    # Итерируемся по всем возможным началам часовых интервалов.
    # Так как максимальное время рекламы 10^9, то итерироваться нужно до этого значения,
    # хотя по факту хватило бы и до самой поздней рекламы. Это неэффективно, но зато просто.
    for start_time in range(0, 1000000): 
        end_time = start_time + 3600  # Вычисляем конец интервала

        total_time = 0 # Обнуляем сумму времени рекламы в текущем интервале

        # Проходим по всем рекламным вставкам
        for ad_start, ad_end in ads:
            # Вычисляем начало пересечения рекламной вставки и часового интервала
            intersection_start = max(start_time, ad_start)
            # Вычисляем конец пересечения рекламной вставки и часового интервала
            intersection_end = min(end_time, ad_end)

            # Если пересечение существует, прибавляем его длину к общему времени рекламы
            if intersection_start < intersection_end:
                total_time += (intersection_end - intersection_start)

        # Если суммарное время рекламы превышает допустимое значение, выводим начало интервала и завершаем программу
        if total_time > t_max:
            print(start_time)
            return

    # Если ни один интервал не нарушил ограничение, выводим -1
    print("-1")

solve()